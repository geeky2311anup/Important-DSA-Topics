# ✨ Minimum Operations to Make Array Values Divisible by 3 — Explanation & Code ✨

> **Tired of overcomplicated codes? Here’s the simplest solution you’ll ever need!**

---

## 🎯 **Intuition**

> The goal is to make every element of the array divisible by **3**.  
> For any number `x`, if `x % 3 == 0`, it already satisfies the condition.  
> Otherwise, we must perform **one operation** on it (either +1 or -1) to reach the nearest multiple of 3.  
> So each number that is **not divisible by 3** contributes **exactly 1** required operation.

---

## 🎯 **What I want to do (high-level goal)**

> - Check each number in the array.  
> - If it is divisible by 3 → do **nothing**.  
> - If not divisible by 3 → count **one operation**.  
> - Sum all such counts.

---

## 🧠 **Why this works**

> - Every integer `x` has only two possibilities when divided by 3:  
>   - Remainder **0** → no change needed  
>   - Remainder **1** or **2** → one step away from nearest multiple of 3  
> - So **each non-multiple-of-3 contributes exactly 1 operation**, no matter what.  
> - The problem becomes simply counting numbers with `x % 3 != 0`.

---

## 🔧 **Approach (step-by-step)**

> 1. Initialize `operations = 0`.  
> 2. Loop over all numbers in `nums`.  
> 3. For each number `x`, compute `remainder = x % 3`.  
> 4. If remainder is not 0 → increment `operations`.  
> 5. Return the final count.

---

## 🔍 **Dry Run Example**

> nums = `[1, 3, 5, 6]`  
>  
> - 1 % 3 = 1 → +1 operation  
> - 3 % 3 = 0 → already divisible  
> - 5 % 3 = 2 → +1 operation  
> - 6 % 3 = 0 → okay  
>
> Total operations = **2**

---

## 📊 **Complexity**

> - **Time Complexity:** `O(n)` — single pass  
> - **Space Complexity:** `O(1)` — constant extra memory

---

## 💻 **Code**

```java
class Solution {
    public int minimumOperations(int[] nums) {
        // Counter to store the number of operations needed
        int operations = 0;

        // Traverse through each number in the array
        for (int x : nums) {
            // Find the remainder when divided by 3
            int remainder = x % 3;

            // If remainder is not zero, the number is not divisible by 3
            // So we need one operation to make it divisible by 3
            if (remainder != 0) {
                operations++;
            }
        }

        // Return the total number of operations required
        return operations;
    }
}

