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

        /*
           STEP 1:
           Sort meetings according to start time
           so meetings are processed in chronological order
        */
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);

        /*
           usage[i]
           stores how many meetings room i handled
        */
        int[] usage = new int[rooms];

        /*
           nextFree[i]
           stores the next time when room i becomes free

           Initially all values are 0,
           meaning all rooms are free at time 0
        */
        long[] nextFree = new long[rooms];

        /*
           STEP 2:
           Process every meeting one by one
        */
        for (int[] meet : meetings) {

            int start = meet[0];
            int end = meet[1];

            // Stores selected room index
            int chosenRoom = -1;

            /*
               STEP 2A:
               Find the first available room
               whose free time <= current meeting start
            */
            for (int room = 0; room < rooms; room++) {

                if (nextFree[room] <= start) {
                    chosenRoom = room;
                    break;
                }
            }

            /*
               STEP 2B:
               If no room is free,
               delay the meeting
            */
            if (chosenRoom == -1) {

                long earliestTime = Long.MAX_VALUE;

                /*
                   Find room which becomes free earliest
                */
                for (int room = 0; room < rooms; room++) {

                    if (nextFree[room] < earliestTime) {

                        earliestTime = nextFree[room];
                        chosenRoom = room;
                    }
                }

                /*
                   Delay meeting

                   duration = end - start

                   new end time =
                   earliest free time + duration
                */
                nextFree[chosenRoom] =
                        earliestTime + (end - start);
            }

            /*
               STEP 2C:
               Room is already free,
               schedule normally
            */
            else {
                nextFree[chosenRoom] = end;
            }

            /*
               Increase usage count
            */
            usage[chosenRoom]++;
        }

        /*
           STEP 3:
           Find room with maximum meetings
        */
        int answer = 0;

        for (int i = 1; i < rooms; i++) {

            /*
               If current room handled more meetings,
               update answer
            */
            if (usage[i] > usage[answer]) {
                answer = i;
            }
        }

        /*
           STEP 4:
           Return room index
        */
        return answer;
    }
}
