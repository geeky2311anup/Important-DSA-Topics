# 🌟 LeetCode – Find Final Value (Bitmask + Math Intuition)

## 🔍 Problem Summary
You repeatedly check if the current value `k` exists in the array.  
If yes → multiply it by `2`.  
Stop when `k` no longer exists in the array.  
Return the final value.

This solution avoids repeatedly searching by converting the problem into simple bitmask logic.

---

## 💡 Intuition
A number can only affect our answer if it is of the form:

k * 2^p

typescript
Copy code

If a number `nums[i]` is divisible by `k`:

nums[i] / k = 2^p

csharp
Copy code

So the core idea:
- Take every number divisible by `k`
- Reduce it by dividing with `k`
- If the result is a **power of two**, mark that power using a bitmask
- The **first missing power of two** gives the answer

This avoids repeated array scans and makes the solution O(n).

---

## 🧠 Approach
1. Create `mask` to track seen powers of 2.
2. Loop through each number:
   - Ignore numbers not divisible by `k`
   - Compute `reduced = num / k`
   - If `reduced` is a power of two → mark its bit in `mask`
3. After processing:
   - Find the smallest bit NOT set in `mask`
   - Answer = `k * 2^missingPower`

---

## 💻 Code (Java – Non-plagiarized)

```java
class Solution {
    public int findFinalValue(int[] nums, int k) {
        long mask = 0L;

        for (int val : nums) {
            if (val % k != 0) continue;

            int reduced = val / k;

            // check if reduced is a power of two
            if (reduced > 0 && (reduced & (reduced - 1)) == 0) {
                int bit = Integer.numberOfTrailingZeros(reduced);
                mask |= (1L << bit);
            }
        }

        // find smallest missing bit
        int power = 0;
        while ((mask & (1L << power)) != 0) {
            power++;
        }

        long result = (long) k * (1L << power);
        return (int) result;
    }
}
```
⏱️ Complexity
Time Complexity: O(n)
Space Complexity: O(1)

✅ Summary
Only values of the form k × 2^p matter

Convert them to powers of 2 by dividing by k

Track seen powers using a bitmask

Final answer = k × 2^firstMissingPower
