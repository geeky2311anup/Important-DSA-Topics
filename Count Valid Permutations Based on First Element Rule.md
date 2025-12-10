# 🤔 Am I the only one who solved this in such a simple way? 😌✨  
### (Problem: **Count Valid Permutations Based on First Element Rule**)

---

## 🎯 Intuition — what you want to do  
> You are given an array `complexity[]`.  
> You want to count **how many permutations of this array are valid**, where the rule is:  
>
> **The first element must be strictly the smallest element of the entire array.**
>
> If the very first element is *not* strictly the smallest → **answer is 0 immediately**.

After that, you are free to reorder the remaining `n-1` elements in **any possible way**, so the answer is simply:

\[
\text{number of valid permutations} = (n-1)! \mod 10^9+7
\]

---

## 🎯 What you want to do (high-level explanation)  
> - Check if `complexity[0]` is the smallest *strict* element of the array.  
> - If ANY other element is **≤ complexity[0]**, the rule breaks → return **0**.  
> - Otherwise the first element is fixed, and the remaining `n-1` positions can be permuted freely.  
> - Number of permutations of these `n-1` elements = **(n-1)!**.  
> - Compute factorial under modulo.

That’s literally it — super clean! 😄

---

## 🧠 Why this works  
> - The condition “first element must be strictly smallest” restricts the first position to exactly **one** element.  
> - Once that is fixed, no other restriction applies → all remaining elements are free to permute.  
> - So total valid permutations = permutations of the remaining `n-1` elements.  
> - Factorial formula gives that count directly.  

No need for DP, combinatorics tricks, or sorting — just a simple check + factorial.

---

## 🔧 Approach (step-by-step)

### **1️⃣ Verify strict smallest condition**
Iterate over the array:

- If any `complexity[i] <= complexity[0]` (for i>0),  
  → **invalid configuration**, return 0.

### **2️⃣ Compute factorial (n-1)!**
Multiply numbers from `2` to `n-1`, taking modulo each step:

\[
ans = (n-1)! \mod MOD
\]

### **3️⃣ Return result**

---

## 🧪 Dry Run

Let:  
`complexity = [3, 5, 7, 10]`

- First element = 3  
- All other elements > 3 → valid  

Then answer = `(4–1)! = 3! = 6`.

Valid permutations of `[5,7,10]` are (3 is fixed in front):

`3 5 7 10`  
`3 5 10 7`  
`3 7 5 10`  
`3 7 10 5`  
`3 10 5 7`  
`3 10 7 5`

Total = **6** ✔️  

---

## 📊 Complexity  
- **Time:** O(n) for checking + O(n) for factorial  
- **Space:** O(1)  

---

## 💻 Code

```java
class Solution {
    public int countPermutations(int[] complexity) {
        final long MOD = 1_000_000_007L;
        int n = complexity.length;

        // Check if the first element is strictly the smallest
        int smallest = complexity[0];
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= smallest) {
                return 0; // invalid configuration
            }
        }

        // compute (n-1)! mod MOD
        long ans = 1;
        for (int k = 2; k <= n - 1; k++) {
            ans = (ans * k) % MOD;
        }

        return (int) ans;
    }
}
