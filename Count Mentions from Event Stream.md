# 🤔 Am I the only one who solved this in such a simple way? 😌✨  
### (Problem: **Count Mentions from Event Stream**)

---

## 🎯 Intuition — what you want to do  
> You receive a chronological stream of events (OFFLINE / MESSAGE) with timestamps. For each MESSAGE you must parse mention tokens (`ALL`, `HERE`, `idX`) and increment mention counters for the appropriate users. OFFLINE events temporarily mark users offline for 60 seconds — they don't become “HERE” during that window.  
>
> The clean strategy: **process events grouped by timestamp** (so all actions at a given second take that second’s state into account), **reactivate** users whose offline window expired at the current time, **apply new OFFLINEs**, then handle MESSAGEs using the updated online/blocked state.

---

## 🎯 What you want to do (high-level goal / why)  
> - Group events by timestamp so actions in the same second are applied consistently.  
> - Before processing a timestamp, reactivate anyone whose `blockedUntil` ≤ now.  
> - Apply OFFLINE events in the batch immediately (they set `online[id] = false` and `blockedUntil = now + 60`).  
> - Then handle MESSAGE events in the same batch:  
>   - `ALL` increments every user's counter.  
>   - `HERE` increments only currently online users.  
>   - `idX` increments that user's counter if `X` is a valid id.  
> - Return final mention counts per user.

Grouping by time and ordering the three steps (reactivate → apply OFFLINE → process MESSAGE) ensures correctness and matches the semantics described.

---

## 🧠 Why this works  
> - Reactivating first ensures people whose offline windows ended at `now` are counted as online for messages at `now`.  
> - Applying OFFLINE events next makes users immediately unavailable for MESSAGEs in the same second (the problem statement implied OFFLINE takes effect in that time slot).  
> - Handling MESSAGEs after these updates means tokens `HERE` reflect the exact set of users online for that second, and `ALL` always hits everyone regardless of online status.  
> - Using arrays (`online[]`, `blockedUntil[]`, `result[]`) gives O(1) checks and updates per user/token and keeps everything efficient.

---

## 🔧 Approach (matching the implementation)

### 1) Group events by timestamp  
> Use a `TreeMap<Integer, List<List<String>>>` so timestamps are processed in ascending order. Each event is a `List<String>` with a structure like `["OFFLINE", "time", "id"]` or `["MESSAGE", "time", "text"]`.

### 2) Maintain state arrays
> - `boolean[] online` — whether user is currently online. (Initialized `true` for everyone.)  
> - `int[] blockedUntil` — timestamp until which user is offline (exclusive or inclusive per spec — code uses `blockedUntil <= now` to reactivate).  
> - `int[] result` — mention counts for each user.

### 3) For each timestamp `now` do:
> 1. Reactivate users: if `!online[u] && blockedUntil[u] <= now` → `online[u] = true, blockedUntil[u] = 0`.  
> 2. Apply OFFLINE events in this batch: set `online[id] = false` and `blockedUntil[id] = now + 60`.  
> 3. Process MESSAGE events in this batch:
>    - Split message text on whitespace into tokens.
>    - For token `ALL` → increment all `result[u]`.  
>    - For token `HERE` → increment `result[u]` only if `online[u]` is `true`.  
>    - For token starting `id` → parse the integer after `id`; if valid range, increment that `result[id]`.

---

## 🔍 What each part contributes (detailed)

### `timeBuckets` (TreeMap)
> groups events by timestamp in ascending order so batch semantics are correct and deterministic.

### `online[]`
> the immediate availability used for `HERE` mentions.

### `blockedUntil[]`
> tracks offline windows so users automatically rejoin when their offline interval expires.

### OFFLINE handling
> makes users unavailable **immediately** in the same second and for the next 60 seconds.

### MESSAGE handling
> uses tokens to decide which users to increment and relies on `online[]` and `blockedUntil[]` having been updated properly for the current time.

---

## 🧪 Dry Run (compact example)

Assume `numberOfUsers = 3` and events:
["OFFLINE","10","1"]
["MESSAGE","10","ALL"]
["MESSAGE","69","HERE"]
["MESSAGE","70","id1"]

csharp
Copy code

Processing:
- time = 10:
  - Reactivate none (all initially online).
  - Apply OFFLINE for id=1 → online[1]=false, blockedUntil[1]=70.
  - MESSAGE "ALL" at time 10 → increments result[0..2] each by 1 (id1 is counted for ALL even though offline).
- time = 69:
  - Reactivate none (blockedUntil[1]==70 > 69).
  - No OFFLINEs.
  - MESSAGE "HERE" → increments only currently online users (id 0 and 2), id1 is offline so not incremented.
- time = 70:
  - Reactivate id1 because blockedUntil[1] <= 70 → online[1]=true.
  - No OFFLINEs.
  - MESSAGE "id1" → increments result[1] by 1.

Final result: counts reflect ALL at 10, HERE at 69, and id1 at 70 with proper offline handling.

---

## 📊 Complexity

> - Let `E` = number of events, `U` = numberOfUsers, `T` = distinct timestamps.  
> - Grouping: `O(E log T)` to insert into `TreeMap` (T ≤ E).  
> - For each timestamp:  
>   - Reactivation step as written loops all users → `O(U)` per timestamp (can be optimized using a priority queue or map of reactivation times if U × T is large).  
>   - Processing batch: depends on batch size and tokens — overall `O(total tokens + U)` in worst case for `ALL/HERE` handling.  
> - Overall worst-case (current implementation): `O(E log E + T * U + totalTokens)`.  
> - Space: `O(E + U)` for buckets and arrays.

> Note: If `U` and `T` can be large this implementation can be optimized by tracking users that are currently offline in a min-heap keyed by `blockedUntil` to reactivate only those whose time has come, avoiding the `O(U)` sweep per timestamp.

---

## 💻 Code

```java
import java.util.*;

class Solution {
    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        // group incoming events by timestamp (ascending)
        TreeMap<Integer, List<List<String>>> timeBuckets = new TreeMap<>();
        for (List<String> ev : events) {
            int t = Integer.parseInt(ev.get(1));
            timeBuckets.computeIfAbsent(t, k -> new ArrayList<>()).add(ev);
        }

        int[] result = new int[numberOfUsers];
        boolean[] online = new boolean[numberOfUsers];
        int[] blockedUntil = new int[numberOfUsers];
        Arrays.fill(online, true); // everyone starts online

        for (Map.Entry<Integer, List<List<String>>> entry : timeBuckets.entrySet()) {
            int now = entry.getKey();
            List<List<String>> batch = entry.getValue();

            // first: reactivate users whose offline period expired at or before `now`
            for (int u = 0; u < numberOfUsers; u++) {
                if (!online[u] && blockedUntil[u] <= now) {
                    online[u] = true;
                    blockedUntil[u] = 0;
                }
            }

            // apply OFFLINE events (they take effect immediately in this time slot)
            for (List<String> ev : batch) {
                if ("OFFLINE".equals(ev.get(0))) {
                    int id = Integer.parseInt(ev.get(2));
                    if (id >= 0 && id < numberOfUsers) {
                        online[id] = false;
                        blockedUntil[id] = now + 60; // offline for next 60 seconds
                    }
                }
            }

            // handle MESSAGE events and count mentions
            for (List<String> ev : batch) {
                if (!"MESSAGE".equals(ev.get(0))) continue;

                String mentionText = ev.get(2);
                if (mentionText == null || mentionText.isEmpty()) continue;

                String[] tokens = mentionText.split("\\s+");
                for (String tok : tokens) {
                    if ("ALL".equals(tok)) {
                        for (int u = 0; u < numberOfUsers; u++) result[u]++;
                    } else if ("HERE".equals(tok)) {
                        for (int u = 0; u < numberOfUsers; u++) {
                            if (online[u]) result[u]++;
                        }
                    } else if (tok.startsWith("id")) {
                        try {
                            int id = Integer.parseInt(tok.substring(2));
                            if (id >= 0 && id < numberOfUsers) result[id]++;
                        } catch (NumberFormatException ignore) { }
                    }
                }
            }
        }

        return result;
    }
}
