### problem link- > https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/
# 1437. Check If All 1's Are at Least Length K Places Away

## Intuition
We are given a binary array `nums`, where `nums[i]` is either 0 or 1.  
We need to verify that **any two consecutive 1’s** are at least `k` indices apart.  
This means that between every two 1s, there should be **at least `k` zeros**.

Instead of storing all indices of 1s, we can track the **distance between consecutive 1s** as we iterate through the array once.

---

## Approach
1. Initialize a variable `count = k`, which represents the number of zeros since the last 1 (initialized to `k` so that the first 1 is always valid).
2. Traverse the array:
   - If the current element is `1`:
     - Check if the previous distance (`count`) is **less than k**.  
       If yes → two 1’s are too close → return `false`.
     - Otherwise, reset `count = 0` since we just found a new 1.
   - If the current element is `0`:
     - Increment `count++` to record one more zero since the last 1.
3. If the loop finishes without conflict, return `true`.

This ensures that all 1’s are spaced by at least `k` zeros.

---

## Dry Run
**Example:**  
nums = [1,0,0,0,1,0,0,1], k = 2

pgsql
Copy code

| Index | nums[i] | count | Action | Result |
|--------|----------|--------|---------|----------|
| 0 | 1 | count = k (valid) → reset count=0 | ✅ |
| 1 | 0 | count=1 | |
| 2 | 0 | count=2 | |
| 3 | 0 | count=3 | |
| 4 | 1 | count=3 ≥ k → valid, reset count=0 | ✅ |
| 5 | 0 | count=1 | |
| 6 | 0 | count=2 | |
| 7 | 1 | count=2 ≥ k → valid, reset count=0 | ✅ |

✅ All pairs of 1s are at least 2 apart → return `true`.

---

## Complexity
- **Time Complexity:** O(n) — single pass through the array.  
- **Space Complexity:** O(1) — only uses a few integer variables.

---

## Code
```java
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int n = nums.length;

        // This variable keeps track of the number of zeros
        // between two consecutive 1s.
        // It starts at k so that the first 1 is always valid.
        int count = k;

        // Traverse through the array
        for (int i = 0; i < n; i++) {

            // If we encounter a 1
            if (nums[i] == 1) {

                // If the number of zeros between the current 1
                // and the previous 1 is less than k,
                // the condition is violated.
                if (count < k) {
                    return false;
                }

                // Reset the counter after encountering a 1
                // because we start counting zeros again.
                count = 0;
            } else {
                // If the current element is 0,
                // increase the distance counter.
                count++;
            }
        }

        // If no violations were found, return true
        return true;
    }
}

