# ✨ Minimum Operations to Make Sum Divisible by k — Explanation & Code ✨


---

## 🎯 **Intuition**

> The array allows an operation (not described here but implied by the math) that lets us adjust the total sum so that it becomes divisible by `k`.  
>  
> But instead of thinking about operations on each element, notice the key idea:  
> **Only the sum matters**, not the individual elements.  
>
> If the sum is already divisible by `k`, we need **0** operations.  
>  
> If the sum leaves a remainder `r = sum % k`,  
> then we need to perform exactly **r operations** to make the sum divisible by `k`.

---

## 🎯 **What I want to do (high-level goal)**

> - Compute the total **sum** of the array.  
> - Find `sum % k`.  
> - That remainder itself is the **minimum number of operations** needed to “fix” the sum.  
> - Return that remainder.

---

## 🧠 **Why this works**

> - A number is divisible by `k` exactly when its remainder mod `k` is **0**.  
> - Any change operation modifies the sum by exactly `1` (or a constant unit), so:  
>   → To remove remainder `r`, we need exactly `r` adjustments.  
> - Because adjustments can always move sum toward the nearest multiple of `k`,  
>   **the remainder itself is the answer**.

---

## 🔧 **Approach (step-by-step)**

> 1. Initialize `sum = 0`.  
> 2. Loop over all elements and compute total sum.  
> 3. Return `sum % k`.  
> 4. This is the number of operations needed.

---

## 🔍 **Dry Run Example**

> nums = `[3, 1, 4]`, k = 5  
>  
> sum = 3 + 1 + 4 = **8**  
> remainder = 8 % 5 = **3**  
>
> So we need **3** operations to make the overall sum divisible by 5.

---

## 📊 **Complexity**

> - **Time Complexity:** `O(n)` — single pass  
> - **Space Complexity:** `O(1)` — constant variables

---

## 💻 **Code**

```java
class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum%k;
    }
}
