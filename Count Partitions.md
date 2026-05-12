# 🤔 Am I the only one who solved **Count Beautiful Partitions** in such a simple way? 😌✨  
*(When everyone overthinks parity… but you don’t.)*

---

## 🎯 Problem Name  
**“Count Partitions”** (LeetCode / Similar Variant)

---

## 🎯 Intuition — what you want to do  
> You want to split the array into **two non-empty partitions** at every index `i`,  
> such that the difference between their sums is **even**.  
>
> That is, for prefix sum `P` and total sum `S`:
>
> \[
(P - (S - P)) \% 2 == 0
\]
>
> Which simplifies beautifully to:
>
> 👉 **Total sum must have the same parity as 2×P**  
> 👉 Which further simplifies to:  
> **P and S must have the same parity**

So the whole problem becomes:

### Count how many prefix sums have **the same parity** (even/odd) as the total sum.

---

## 🎯 What you want to do (high-level thinking)
- Compute total sum `S`.  
- Build prefix sums one by one.  
- For each valid split point `i < n-1`:  
  - Check if `(prefixSum - (S - prefixSum)) % 2 == 0`.  
  - This is equivalent to checking parity match.  
- Count such positions.

This turns a complicated-sounding task into a **simple parity check**.

---

## 🧠 Why this works  
> - Let prefix sum = P  
> - Let suffix sum = S - P  
> - We want `(P - (S - P)) % 2 == 0`  
> - That is:  
\[
(2P - S) \% 2 == 0
\]
> - Since `2P % 2 = 0`, we get:
\[
S \% 2 == 0
\]
So the condition holds when:

### 💡 Prefix sum P has **same parity** as total sum S.

Every split where P is even and S is even,  
or P is odd and S is odd → **valid**.

---

## 🔧 Approach (matching your implementation)

1. Compute total sum `S`.
2. Iterate from index `0` to `n-2`, building prefix sum `P`.
3. For each split:
   - If `(P - (S - P)) % 2 == 0`, increment count.
4. Return count.

Perfectly efficient and extremely clean.

---

## 🧪 Dry Run Example

Input:  
nums = [3, 1, 4, 2]
Total sum S = 10 (even)

yaml
Copy code

Prefix sums:
- i=0 → P = 3 → (3 - 7) % 2 = even → count++
- i=1 → P = 4 → (4 - 6) % 2 = even → count++
- i=2 → P = 8 → (8 - 2) % 2 = even → count++

Answer = **3**

---

## 📊 Complexity

> - **Time:** O(n)  
> - **Space:** O(1)  

---

## 💻 Code

```java
class Solution {

    public int countPartitions(int[] nums) {

        // Length of the array
        int n = nums.length;

        // Stores total sum of all elements
        int totalSum = 0;

        // Final answer:
        // number of valid partitions
        int validPartitions = 0;

        // ----------------------------------------
        // Step 1: Calculate total array sum
        // ----------------------------------------
        for (int value : nums) {
            totalSum += value;
        }

        // Prefix sum will store sum of left partition
        int prefixSum = 0;

        // -------------------------------------------------
        // Step 2: Try every possible partition point
        // -------------------------------------------------
        // We stop at n-2 because both partitions
        // must contain at least one element.
        //
        // Example:
        // nums = [1,2,3,4]
        //
        // i = 0  -> [1] | [2,3,4]
        // i = 1  -> [1,2] | [3,4]
        // i = 2  -> [1,2,3] | [4]
        // -------------------------------------------------
        for (int i = 0; i < n - 1; i++) {

            // Add current element to left partition
            prefixSum += nums[i];

            // Right partition sum
            int suffixSum = totalSum - prefixSum;

            // Difference between left and right sums
            int difference = prefixSum - suffixSum;

            // ------------------------------------------------
            // If difference is even, partition is valid
            //
            // Why?
            // Because:
            // (leftSum - rightSum) % 2 == 0
            //
            // means both sums have same parity
            // (both even or both odd)
            // ------------------------------------------------
            if (difference % 2 == 0) {
                validPartitions++;
            }
        }

        // Return total valid split count
        return validPartitions;
    }
}
