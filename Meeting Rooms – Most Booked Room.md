# 🤔 Am I the only one who solved **Meeting Rooms – Most Booked Room** without fancy heaps? 😌✨

---

## 🧩 Problem Name  
**Meeting Rooms III – Most Booked Room** (LeetCode)

---

## 🎯 Intuition — what you want to do  
> You are given:
> - `rooms` → total number of meeting rooms  
> - `meetings[i] = [start, end]` → meetings sorted by **start time** (after sorting)
>
> Rules:
> - A meeting should go to the **lowest-index room** that is free at its start time.
> - If **no room is free**, the meeting is **delayed** until the earliest room becomes free.
> - Delayed meeting keeps the **same duration**.
>
> Goal:
> 👉 **Find the room that gets booked the most times.**  
> (If tie, return the smallest index.)

---

## 🎯 What you want to do (high-level goal / why)  
> - Track **when each room becomes free**.
> - Process meetings in chronological order.
> - For each meeting:
>   - Try to assign a room immediately.
>   - If not possible, delay it to the earliest available room.
> - Count how many times each room is used.
> - Return the room with maximum usage.

Why greedy?
> Because meetings must be assigned **as early as possible** and **lowest-index priority** must be respected.

---

## 🧠 Why this works  
> - Meetings are processed in increasing start time.
> - Each meeting either:
>   - Fits into a currently free room, or
>   - Gets delayed to the earliest freeing room.
> - Since we always choose:
>   - the **lowest index free room**, or
>   - the **earliest available room** when delaying,
>   we perfectly match the problem constraints.
>
> The usage count naturally tells us which room was booked the most.

This is a **greedy simulation** problem.

---

## 🔧 Approach (matching the implementation)

### 1) Sort meetings by start time  
> Ensures we process meetings in the correct chronological order.

---

### 2) Maintain two arrays  
> - `nextFree[r]` → when room `r` becomes free  
> - `usage[r]` → how many meetings room `r` handled  

Initially:
---

### 4) Find the most booked room  
> Scan `usage[]` and return the index with the highest count  
> (ties automatically favor smaller index).

---

## 🔍 What each variable contributes

### `nextFree[]`
> Tracks availability of each room over time.

### `usage[]`
> Counts how many meetings each room handles.

### `chosen`
> Room selected for the current meeting.

---

## 🧪 Dry Run (small example)

Input:
rooms = 2
meetings = [[0,10], [1,5], [2,7], [3,4]]
Steps:
- [0,10] → room 0
- [1,5]  → room 1
- [2,7]  → no free room → delay to room 1 (at 5)
- [3,4]  → no free room → delay to room 0 (at 10)

Usage:
room 0 → 2
room 1 → 2
Answer → **0** (smaller index wins)

---

## 📊 Complexity

> - **Time Complexity:** `O(m × r)`  
>   (m = meetings, r = rooms)
>
> - **Space Complexity:** `O(r)`

*(Yes, priority queues can optimize this, but this version keeps logic crystal clear.)*

---

## 💻 Code

```java
class Solution {
    public int mostBooked(int rooms, int[][] meetings) {

        // Step 1: Sort all meetings based on their start time
        // This ensures we process meetings in chronological order
        Arrays.sort(meetings, (x, y) -> Integer.compare(x[0], y[0]));

        // usage[i] → number of meetings handled by room i
        int[] usage = new int[rooms];

        // nextFree[i] → the next time room i becomes available
        // Use long to avoid overflow when times accumulate
        long[] nextFree = new long[rooms];

        // Step 2: Process each meeting
        for (int[] meet : meetings) {
            int start = meet[0];
            int finish = meet[1];

            int chosen = -1; // room chosen for this meeting

            // Step 2a: Try to find a room that is free at the meeting's start time
            for (int r = 0; r < rooms; r++) {
                if (nextFree[r] <= start) {
                    chosen = r; // room is available
                    break;      // pick the first available room (smallest index)
                }
            }

            // Step 2b: If no room is free, delay the meeting
            // to the earliest available room
            if (chosen == -1) {

                long earliest = Long.MAX_VALUE;

                // Find the room that becomes free the earliest
                for (int r = 0; r < rooms; r++) {
                    if (nextFree[r] < earliest) {
                        earliest = nextFree[r];
                        chosen = r;
                    }
                }

                // Delay the meeting:
                // new start = earliest free time
                // new finish = earliest + duration
                nextFree[chosen] = earliest + (finish - start);
            } 
            else {
                // Room was free at start time, so schedule normally
                nextFree[chosen] = finish;
            }

            // Step 2c: Increase usage count for that room
            usage[chosen]++;
        }

        // Step 3: Find the room with the highest usage
        // If tie, return the smallest room index
        int answer = 0;
        for (int i = 1; i < rooms; i++) {
            if (usage[i] > usage[answer]) {
                answer = i;
            }
        }

        // Step 4: Return the room index with most meetings
        return answer;
    }
}

