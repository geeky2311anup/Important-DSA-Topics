# ✨ Maximum Subarray Sum With Index Modulo Constraint — Explanation & Code ✨

> **When brute force fails, prefix sums + modulo magic save the day!**  
> This is a beautiful problem combining prefix sums, modular indexing, and minimum prefix tracking.

---

## 🎯 **Intuition**

> You want the **maximum subarray sum**, but with a twist:  
> the subarray must satisfy the condition that  
> **(ending index − starting index + 1) % k == 0**  
>
> That means the subarray length must be divisible by **k**.  
>
> This is exactly the same as saying:  
> For a subarray `(l, r)` to be valid,  
> **r % k == (l - 1) % k**  
>
> And how do we detect such index pairs efficiently?  
> → By using **prefix sums grouped by remainder modulo k**.

---

## 🎯 **What I want to do (high-level goal)**

> - Maintain prefix sums as we scan the array.  
> - For each prefix index `i`, compute its remainder `(i + 1) % k`.  
> - To form a valid subarray ending at `i`, we need an earlier prefix with the **same remainder**.  
> - Among all such previous prefixes, choose the one with the **smallest prefix sum** to maximize the subarray result.

---

## 🧠 **Why this works**

> - Prefix sum trick:  
>   A subarray sum `sum(l, r) = prefix[r] − prefix[l−1]`.  
> - The subarray length `(r - l + 1)` is divisible by `k`  
>   ⇔ `(r % k) == ((l - 1) % k)`  
> - So when scanning index `i`, its prefix remainder is  
>   `rem = (i + 1) % k`.  
>
> - If we previously saw any prefix with the same remainder,  
>   subtracting gives a valid subarray of length divisible by `k`.  
>
> - To maximize `prefix[i] − prefix[j]`,  
>   we want the **smallest prefix[j]** among all j with same remainder.  
>
> - Therefore we store for each remainder `r`:  
>   the **minimum prefix sum** seen so far.

---

## 🔧 **Approach (step-by-step)**

> 1. Create an array `bestPrefixForRem[k]` initialized with `INF`.  
> 2. Let prefix remainder **0** have value **0**, representing an empty prefix.  
> 3. Maintain running `prefixSum`.  
> 4. For each index `i`:  
>    - Update `prefixSum += nums[i]`.  
>    - Compute `rem = (i + 1) % k`.  
>    - If we already have a prefix with same `rem`:  
>      - Compute candidate subarray sum:  
>        `prefixSum - bestPrefixForRem[rem]`  
>      - Update best answer.  
>    - Update the minimum stored prefix sum for this remainder.  
> 5. Return `bestAns`.

---

## 🔍 **Dry Run Example (conceptual)**

> Suppose `nums = [4, -1, 2, 1]` and `k = 2`.  
>
> prefix sums:  
> - i=0 → prefix=4, rem=1  
> - i=1 → prefix=3, rem=0  
> - i=2 → prefix=5, rem=1  
>
> When rem repeats, subtract smallest prefix with same rem.

---

## 📊 **Complexity**

> - **Time Complexity:** `O(n)`  
> - **Space Complexity:** `O(k)`

---

## 💻 **Code**

```java
class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;

        final long INF = (long) 4e18;
        long[] bestPrefixForRem = new long[k];

        // initialize with "infinite" values
        for (int r = 0; r < k; r++) {
            bestPrefixForRem[r] = INF;
        }

        long prefixSum = 0L;
        long bestAns = -INF;

        // empty prefix has remainder 0
        bestPrefixForRem[0] = 0L;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            int rem = (i + 1) % k;

            // if we've seen some prefix with same remainder
            if (bestPrefixForRem[rem] != INF) {
                long candidate = prefixSum - bestPrefixForRem[rem];
                if (candidate > bestAns) {
                    bestAns = candidate;
                }
            }

            // update minimal prefix sum for this remainder
            if (prefixSum < bestPrefixForRem[rem]) {
                bestPrefixForRem[rem] = prefixSum;
            }
        }

        return bestAns;
    }
}
8o
