# ✨ Smallest Repunit Divisible by K — Explanation & Code ✨

> **Tired of unnecessary math proofs? Here’s the cleanest and simplest explanation for this beautiful number theory problem!**

---

## 🎯 **Intuition**

> A *repunit* is a number made of only digit **1** like:  
> **1, 11, 111, 1111, ...**  
>  
> We want to find the **smallest length** of such a number that is divisible by `k`.  
>
> Key observation:  
> - If a number has factor **2** or **5**, no repunit can ever be divisible by it.  
>   Because repunits only contain digit `1` → they always end with 1.  
>   So they are **never divisible by 2 or 5**.

---

## 🎯 **What I want to do (high-level goal)**

> - Build repunits gradually:  
>   - `1 → 11 → 111 → 1111 → ...`  
> - Instead of storing huge numbers, keep only the **remainder modulo k**.  
> - Continue until the remainder becomes **0**, which means the repunit is divisible.  
> - Track how many digits (`length`) we have added.

---

## 🧠 **Why this works**

> - A repunit `R(n)` can be built using the recurrence:  
>   **R(n) = (R(n-1) * 10 + 1)**  
> - We only store `R(n) % k`, which remains small (0 to k−1).  
> - If we ever see remainder **0**, we're done — divisible!  
> - If the length exceeds `k`, we know the remainders have started repeating → cycle → no solution.  
>   (Pigeonhole principle: more than `k` remainders means repetition.)

---

## 🔧 **Approach (step-by-step)**

> 1. If `k` is divisible by **2 or 5**, return `-1`.  
> 2. Start with the repunit `"1"` → its remainder is `1 % k`.  
> 3. Extend repunit by appending a `1`:  
>    - New remainder = `(old_remainder * 10 + 1) % k`  
> 4. Increase length each time.  
> 5. Stop when remainder reaches `0`.  
> 6. If length ever exceeds `k`, return `-1` (cycle detected).

---

## 🔍 **Dry Run Example**

> Let `k = 7`  
>
> - length = 1 → "1"     → 1 % 7 = 1  
> - length = 2 → "11"    → (1×10 + 1) % 7 = 4  
> - length = 3 → "111"   → (4×10 + 1) % 7 = 6  
> - length = 4 → "1111"  → (6×10 + 1) % 7 = 5  
> - length = 5 → "11111" → (5×10 + 1) % 7 = 2  
> - length = 6 → "111111"→ (2×10 + 1) % 7 = **0**  
>
> Answer = **6**

---

## 📊 **Complexity**

> - **Time Complexity:** `O(k)` in worst case  
> - **Space Complexity:** `O(1)` (just integers)

---

## 💻 **Code**

```java
class Solution {
    public int smallestRepunitDivByK(int k) {

        // Repunit cannot be divisible by numbers having 2 or 5 as factors
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int remainder = 1 % k;   // remainder of the repunit "1"
        int length = 1;          // length of current repunit

        // Keep extending the repunit: 1, 11, 111, ...
        while (remainder != 0) {
            remainder = (remainder * 10 + 1) % k;  // update modulo
            length++;

            // A repunit longer than k can't give a new remainder → cycle
            if (length > k) return -1;
        }

        return length;
    }
}
