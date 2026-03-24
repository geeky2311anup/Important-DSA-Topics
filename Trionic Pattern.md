
# 💎 This is a Classic 3-Phase Array Traversal Problem (Trionic Pattern)

## 🧩 Overview  

```Problem_Explanation []
You are given an integer array `nums`.

You need to check whether the array follows
a strict 3-phase pattern:

Phase 1 → Strictly Increasing
Phase 2 → Strictly Decreasing
Phase 3 → Strictly Increasing again

This shape is called a "Trionic" pattern.
```

```📥_Input_Output []
📥 Input
nums → integer array

📤 Output
Return true if array follows:
increasing → decreasing → increasing
Else return false
```

## 😎 Think Like

```❌_What_Will_NOT_Work []
🚫 Checking only local peaks
→ misses full pattern structure

🚫 Allowing equal elements (flat)
→ breaks "strict" condition

🚫 Multiple loops restarting from 0
→ unnecessary time complexity

👉 So we use ONE PASS pointer traversal.
```

```✅_Correct_Strategy []
➤ Use pointer i for first increasing phase

➤ Use pointer j to continue traversal

➤ Traverse array in THREE ordered phases:

   Phase 1 → climb up
   Phase 2 → go down
   Phase 3 → climb up again

➤ Validate boundaries after each phase

➤ End pointer must reach last index
```

## ☝️ Lets Visualise

```📊_Visualisation []

Use the provided reference image:

Image Reference:
- Phase 1: Strictly Increasing (Pointer i)
- Phase 2: Strictly Decreasing (Pointer j)
- Phase 3: Strictly Increasing (Pointer j)

Visualization Meaning:

Array Layout:
[ 2 , 4 , 7 , 8 , 8 , 4 , 5 , 6 , 9 ]
  ↑           ↑               ↑
  i         peak(i)        final j

Movement:

Phase 1:
Pointer i moves right while:
nums[i] < nums[i+1]

Phase 2:
Pointer j continues right while:
nums[j] > nums[j+1]

Phase 3:
Pointer j again moves right while:
nums[j] < nums[j+1]

❌ Red cross in image shows:
- Flat values
- Invalid breaks
- Early termination

✔ Green arrows show valid pointer flow

```

```🧪_Dry_Run []

Example:
nums = [2,4,7,8,4,5,6]

Step 1:
i = 0

Phase 1 (Increasing):
2 < 4 ✔ → i = 1
4 < 7 ✔ → i = 2
7 < 8 ✔ → i = 3
8 < 4 ❌ stop

i = 3 (first peak)

Phase 2 (Decreasing):
j = i = 3
8 > 4 ✔ → j = 4
4 > 5 ❌ stop

j = 4 (valley)

Phase 3 (Increasing):
4 < 5 ✔ → j = 5
5 < 6 ✔ → j = 6

j == n-1 ✔

Return true

```

---
## 🥇 One-Pass Execution Flow  

In ONE clean traversal:

✔ Pointer i builds first increasing slope

✔ Pointer j builds decreasing valley

✔ Pointer j again builds final increasing slope

✔ No backtracking
✔ No nested loops
✔ Strict comparisons enforced

---

```java
class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        if (n < 4) return false;

        int i = 0;

        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // invalid if no climb or reached end
        if (i == 0 || i == n - 1) return false;

        int j = i;

        // Phase 2: strictly decreasing
        while (j + 1 < n && nums[j] > nums[j + 1]) {
            j++;
        }

        // invalid if no drop or reached end
        if (j == i || j == n - 1) return false;

        // Phase 3: strictly increasing again
        while (j + 1 < n && nums[j] < nums[j + 1]) {
            j++;
        }

        // must end exactly at last index
        return j == n - 1;
    }
}
---

## ⏱ Complexity Analysis

Time Complexity: O(N)
Space Complexity: O(1)

---
---

Even Iron Man failed hundreds of times before building the suit.  
Keep solving — one day your “bugs” become your superpower 💪  

---

If this solution saved even **10 minutes** of your day — please connect with me on **LinkedIn** 🤝  

🅾 𝐈𝐧𝐬𝐭𝐚𝐠𝐫𝐚𝐦: anupsingh5831

Please UpVode

🔥 Let’s grow together!  
