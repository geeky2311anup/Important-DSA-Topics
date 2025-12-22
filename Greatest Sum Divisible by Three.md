# 🤔 Am I the only one who solved **Greatest Sum Divisible by Three** in such a clean greedy way? 😌✨

---

## 🎯 Intuition — what you want to do  
> You are given an integer array `nums`.  
>  
> You can pick **any subset of elements** (at least one) and you want the **maximum possible sum** such that:
>
> ```
> sum % 3 == 0
> ```
>
> Instead of trying all subsets (which is exponential), notice something important:
>
> 👉 **Divisibility by 3 depends only on remainders modulo 3.**

So the entire problem boils down to **smartly combining numbers based on their remainder mod 3**.

---

## 🎯 What you want to do (high-level goal / why)  
> - Track the **largest single number** for each remainder `0, 1, 2`.
> - Track the **largest sum of two numbers** for each remainder `0, 1, 2`.
> - While iterating through the array:
>   - Try to form a sum divisible by 3 using an existing pair.
>   - Update possible new pairs using existing single values.
>   - Update the best single value for the current remainder.
>
> At every step, greedily keep the **best possible sums only** — everything else is useless.

---

## 🧠 Why this works  
> - Any sum divisible by 3 must have remainder `0`.
> - A number with remainder `r` needs another sum with remainder `(3 - r) % 3`.
> - You never need to track all combinations — only the **best sums per remainder**.
> - This guarantees correctness while staying in linear time.

This is a **greedy + modulo DP compression** approach.

---

## 🔧 Approach (matching the implementation)

### 1) Data structures  
> - `bestOne[r]`: largest **single value** seen so far with remainder `r`
> - `bestTwo[r]`: largest **sum of two values** with remainder `r`
> - `best`: answer (largest sum divisible by 3 found so far)

Both arrays have size `3` because remainders are only `{0,1,2}`.

---

### 2) Iterate through each number `x`

#### a) Try to complete a valid divisible-by-3 sum  
> - `x % 3 = rem`
> - We need a previous sum with remainder `(3 - rem) % 3`
> - If such a pair exists:
>
> ```
> best = max(best, bestTwo[need] + x)
> ```

---

#### b) Create new pairs using existing singles  
> For every remainder `r`:
> - If `bestOne[r]` exists:
>   - New remainder = `(bestOne[r] + x) % 3`
>   - Update `bestTwo[newRem]`

This builds the best 2-number combinations.

---

#### c) Update best single value  
> Keep only the **largest** single number for this remainder:
bestOne[rem] = max(bestOne[rem], x)

yaml
Copy code

---

## 🔍 What each structure represents

### `bestOne[]`
> Best single number for each remainder  
> Helps build pairs later.

### `bestTwo[]`
> Best sum of two numbers for each remainder  
> Helps build valid divisible-by-3 sums.

### `best`
> Tracks the maximum valid answer found so far.

---

## 🧪 Dry Run (example)

Input:
nums = [3, 6, 5, 1, 8]

markdown
Copy code

Step-by-step:
- `3` → rem=0 → bestOne[0]=3
- `6` → rem=0 → bestOne[0]=6
- `5` → rem=2 → bestOne[2]=5
- `1` → rem=1 → forms pair (5+1=6) → bestTwo[0]=6
- `8` → rem=2 → completes pair → best = 6+8 = 14

Output:
14

pgsql
Copy code

---

## 📊 Complexity

> - **Time Complexity:** `O(n)`  
> - **Space Complexity:** `O(1)` (constant arrays of size 3)

---

## 💻 Code

```java
class Solution {
    public int maximumSum(int[] nums) {

        // bestOne[r]  -> largest single value with remainder r
        // bestTwo[r]  -> largest sum of two values with remainder r
        int[] bestOne = new int[3];
        int[] bestTwo = new int[3];

        int best = 0;

        for (int x : nums) {
            int rem = x % 3;

            // try to complete a divisible-by-3 sum using existing pairs
            int need = (3 - rem) % 3;
            if (bestTwo[need] > 0) {
                best = Math.max(best, bestTwo[need] + x);
            }

            // create new pairs using existing singles
            for (int r = 0; r < 3; r++) {
                if (bestOne[r] > 0) {
                    int newRem = (bestOne[r] + x) % 3;
                    bestTwo[newRem] = Math.max(bestTwo[newRem], bestOne[r] + x);
                }
            }

            // update best single value for this remainder
            bestOne[rem] = Math.max(bestOne[rem], x);
        }

        return best;
    }
}
