# 🤔 Am I the only one who solved **Maximum Sum of Two Non-Overlapping Events** in such a simple way? 😌✨

---

## 🎯 Intuition — what you want to do  
> You are given a list of events, where each event is represented as:
>
> ```
> [startTime, endTime, value]
> ```
>
> You can attend **at most two events**, and the events **must not overlap** in time.  
> Your task is to find the **maximum total value** you can get.

The key realization is:
> 👉 Either you take **one event**, or you take **two non-overlapping events**.

So the problem becomes:  
**For every event, can I find the best event that ends before this one starts?**

---

## 🎯 What you want to do (high-level goal / why)  
> - Sort events by their **end time**.
> - Precompute, for every position, the **maximum value achievable up to that point**.
> - For each event:
>   - Treat it as the second event.
>   - Binary search to find the **last event that ends before it starts**.
>   - Combine their values and update the answer.

This avoids checking all pairs (`O(n²)`) and reduces it to `O(n log n)`.

---

## 🧠 Why this works  
> - Sorting by end time ensures that all valid non-overlapping candidates lie to the **left**.
> - Prefix maximum (`bestTill[]`) lets us instantly know the **best event so far**.
> - Binary search efficiently finds the last compatible event.
> - Every valid pair is considered exactly once.

This is a classic **interval DP + binary search optimization**.

---

## 🔧 Approach (matching the implementation)

### 1) Sort events by end time  
> This ensures earlier-ending events appear first.

---

### 2) Build helper arrays  
> - `endTimes[i]`: end time of the `i-th` event after sorting  
> - `bestTill[i]`: maximum event value among events `[0..i]`

So:
bestTill[i] = max(bestTill[i-1], events[i][2])

yaml
Copy code

---

### 3) Try every event as the second event  
For each event `i`:
> - Take it alone → update answer  
> - Binary search for the **rightmost event ending before `start[i]`**  
> - If found at index `idx`, combine:
events[i][2] + bestTill[idx]

yaml
Copy code

---

### 4) Binary search logic  
> Find the largest index `< i` such that:
endTimes[index] < startTime

yaml
Copy code

This guarantees **no overlap**.

---

## 🔍 What each part contributes (detailed)

### `bestTill[]`
> Stores the best single-event value up to each index.  
> Avoids recomputing maximums repeatedly.

### `endTimes[]`
> Allows binary search over event end times.

### `findLastNonOverlapping()`
> Efficiently locates the last compatible event in `O(log n)` time.

### `answer`
> Tracks the best value using either one event or two non-overlapping events.

---

## 🧪 Dry Run (small example)

Events:
[1,2,4], [3,4,3], [2,3,1]

pgsql
Copy code

After sorting by end time:
[1,2,4], [2,3,1], [3,4,3]

yaml
Copy code

`bestTill = [4, 4, 4]`

Now:
- Event `[3,4,3]`
  - start = 3
  - last end < 3 → index 0
  - value = 3 + 4 = 7 ✅

Answer = **7**

---

## 📊 Complexity

> - **Time Complexity:** `O(n log n)`  
>   - Sorting: `O(n log n)`  
>   - Binary search for each event: `O(log n)`
>
> - **Space Complexity:** `O(n)`  
>   - Helper arrays `endTimes[]` and `bestTill[]`

---

## 💻 Code

```java
import java.util.Arrays;

class Solution {

    public int maxTwoEvents(int[][] events) {
        int n = events.length;

        // Step 1: Sort all events based on their end times.
        // This allows us to use binary search to find events that end 
        // before a specific start time.
        Arrays.sort(events, (e1, e2) -> Integer.compare(e1[1], e2[1]));

        // endTimes: Stores the sorted end times for binary search lookups.
        int[] endTimes = new int[n];
        // bestTill: Prefix maximum array where bestTill[i] stores the 
        // maximum value of any single event from index 0 to i.
        int[] bestTill = new int[n];

        for (int i = 0; i < n; i++) {
            endTimes[i] = events[i][1];
            bestTill[i] = events[i][2];
            // If there's a previous event with a higher value, carry it forward.
            if (i > 0) {
                bestTill[i] = Math.max(bestTill[i], bestTill[i - 1]);
            }
        }

        // Initialize answer with the highest value of a single event.
        int answer = bestTill[n - 1];

        // Step 2: Iterate through each event and treat it as the "second" event.
        for (int i = 0; i < n; i++) {
            int startOfCurrent = events[i][0];
            int valueOfCurrent = events[i][2];

            // Consider the current event by itself.
            answer = Math.max(answer, valueOfCurrent);

            // Step 3: Use binary search to find the latest event that ends 
            // before the current event starts (non-overlapping).
            int idx = findLastNonOverlapping(endTimes, startOfCurrent, i);
            
            if (idx != -1) {
                // If a non-overlapping event exists, add its best prefix value 
                // to the current event's value.
                answer = Math.max(answer, valueOfCurrent + bestTill[idx]);
            }
        }

        return answer;
    }

    /**
     * Standard binary search to find the rightmost index such that 
     * endTimes[index] is strictly less than the target start time.
     */
    private int findLastNonOverlapping(int[] endTimes, int target, int limit) {
        int lo = 0, hi = limit - 1;
        int pos = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (endTimes[mid] < target) {
                // This event ends before the target; it's a candidate.
                // Try to find an even later one (move right).
                pos = mid;
                lo = mid + 1;
            } else {
                // This event overlaps or ends too late; move left.
                hi = mid - 1;
            }
        }
        return pos;
    }
}
