# 😏 Is this really a DP problem… or just smart counting in disguise? 😌✨

---

## 🎯 Problem Name  
**Number of Ways to Paint N × 3 Grid**

---

## 🎯 Intuition — what you want to do  
> You are given an `n × 3` grid.  
>  
> You must paint every cell using **3 colors**, such that:
> - No two adjacent cells (horizontally or vertically) have the same color.
>
> You need to return the **total number of valid ways** to paint the grid.

At first glance it screams **DP**, but the trick is to **reduce states smartly**.

---

## 🎯 What you want to do (high-level goal / why)  
> Instead of tracking all color combinations, classify each row into **two pattern types**:
>
> - **same** → patterns where the first and third cell have the same color  
>   (example: `A B A`)
>
> - **diff** → patterns where all three cells are different  
>   (example: `A B C`)
>
> For each row, count how many ways we can form:
> - `same` patterns  
> - `diff` patterns  
>
> Then transition row-by-row.

Why this works:
> Any valid coloring of a row **must fall into one of these two categories**.

---

## 🧠 Why this works  
> - For the **first row**, there are:
>   - `6` ways to form `same` patterns  
>   - `6` ways to form `diff` patterns  
>
> - For every next row:
>   - The number of valid transitions depends only on whether the previous row was `same` or `diff`.
>   - We derive recurrence relations based on color constraints.
>
> This avoids exponential states and gives a clean `O(n)` solution.

---

## 🔧 Approach (matching your implementation)

### 1) Base initialization (row = 1)
> - `same = 6`  
> - `diff = 6`  

These represent all valid patterns for the first row.

---

### 2) Transition for each next row
For every new row:
> - New `same` patterns can be formed from:
>   - `3 * same`  
>   - `2 * diff`
>
> - New `diff` patterns can be formed from:
>   - `2 * same`  
>   - `2 * diff`

So:
nextSame = 3same + 2diff
nextDiff = 2same + 2diff

yaml
Copy code

Apply modulo at each step.

---

### 3) Final answer
> Total ways = `same + diff` after processing all `n` rows.

---

## 🔍 What each variable represents

### `same`
> Number of valid colorings for current row where 1st and 3rd cells have the same color.

### `diff`
> Number of valid colorings for current row where all 3 cells are different.

### `nextSame`, `nextDiff`
> Updated counts for the next row based on valid transitions.

---

## 🧪 Dry Run (small example)

### n = 1
same = 6
diff = 6
answer = 12

shell
Copy code

### n = 2
nextSame = 36 + 26 = 30
nextDiff = 26 + 26 = 24
answer = 54

yaml
Copy code

Correct and efficient.

---

## 📊 Complexity

> - **Time Complexity:** `O(n)`  
> - **Space Complexity:** `O(1)`  

Only constant variables are used.

---

## 💻 Code

```java
class Solution {
    public int numOfWays(int n) {
        final int MOD = 1_000_000_007;

        long same = 6;   // patterns with same colors
        long diff = 6;   // patterns with different colors

        for (int row = 2; row <= n; row++) {
            long nextSame = (3 * same + 2 * diff) % MOD;
            long nextDiff = (2 * same + 2 * diff) % MOD;

            same = nextSame;
            diff = nextDiff;
        }

        return (int)((same + diff) % MOD);
    }
}
