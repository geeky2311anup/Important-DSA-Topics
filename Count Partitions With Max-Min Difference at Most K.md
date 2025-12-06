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
        int n = nums.length;
        int sum = 0;
        int count = 0;

        // compute total sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int prefix = 0;

        // check all split points except last (both parts must be non-empty)
        for (int i = 0; i < n - 1; i++) {
            prefix += nums[i];

            // parity check: (prefix - (sum - prefix)) % 2 == 0
            if ((prefix - (sum - prefix)) % 2 == 0) {
                count++;
            }
        }

        return count;
    }
}
