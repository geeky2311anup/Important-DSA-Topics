# 🤔 Am I the only one who solved **Delete Columns to Make Sorted III** in such a simple DP way? 😌✨

---

## 🎯 Intuition — what you want to do  
> You are given a list of strings `strs`, all of the **same length**.  
>  
> You are allowed to **delete columns** (same index across all strings).  
>  
> Your goal is to delete the **minimum number of columns** so that, for every row,  
> the remaining columns form a **non-decreasing sequence** (left to right).
>
> Instead of thinking “which columns to delete”, flip the thinking:
> **Which columns can I keep in order?**

This turns into a **Longest Valid Column Subsequence** problem.

---

## 🎯 What you want to do (high-level goal / why)  
> - Treat each column as a position in a sequence.
> - Find the **maximum number of columns** you can keep such that:
>   - For every pair of kept columns `i < j`
>   - For **all rows `r`**, `strs[r][i] <= strs[r][j]`
> - Once you know the maximum number of columns you can keep (`best`),
>   the answer is simply:
>
> ```
> total_columns - best
> ```

Why this works:
> Minimizing deletions = maximizing kept columns.

---

## 🧠 Why this works  
> - Column order must be preserved → subsequence problem  
> - Validity of extending column `i` to `j` depends on **all rows**, not just one  
> - This is exactly a **Longest Increasing Subsequence–style DP**, but with a custom comparison rule  
> - Number of columns is small enough for `O(cols² × rows)` DP

---

## 🔧 Approach (matching the implementation)

### 1) DP definition  
> `keep[j]` = length of the longest valid column sequence **ending at column `j`**

Initialize:
keep[j] = 1 // each column alone is always valid

yaml
Copy code

---

### 2) Transition  
For every pair of columns `i < j`:
> - Check all rows:
>   - If for any row `r`, `strs[r][i] > strs[r][j]`, then column `j` cannot follow `i`
> - If valid for all rows:
> ```
> keep[j] = max(keep[j], keep[i] + 1)
> ```

---

### 3) Track the best sequence  
> Maintain:
best = max over all keep[j]

yaml
Copy code

---

### 4) Final answer  
> Minimum deletions:
cols - best

yaml
Copy code

---

## 🔍 What each part contributes (detailed)

### `keep[]`  
> Stores the best valid sequence length ending at each column.

### Nested column loops (`i < j`)  
> Tries to extend an earlier column sequence with a later column.

### Inner row loop  
> Ensures **every row** remains non-decreasing — this is the key constraint.

### `best`  
> Length of the longest column subsequence we can keep safely.

---

## 🧪 Dry Run (small example)

Input:
strs = ["babca", "bbazb"]

pgsql
Copy code

Columns (by index):
0 1 2 3 4
b a b c a
b b a z b

markdown
Copy code

Check sequences:
- Column 0 → valid alone
- Column 1 cannot follow 0 (`a < b` in row 0)
- Column 2 can follow 0
- Column 3 can follow 0, 2
- Column 4 breaks many orders

Longest valid keep = **3 columns**

Answer:
5 - 3 = 2 deletions

pgsql
Copy code

---

## 📊 Complexity

> - **Time Complexity:** `O(cols² × rows)`  
> - **Space Complexity:** `O(cols)`  

---

## 💻 Code

```java
class Solution {
    public int minDeletionSize(String[] strs) {

        int rows = strs.length;
        int cols = strs[0].length();

        // keep[j] = longest valid sequence ending at column j
        int[] keep = new int[cols];
        Arrays.fill(keep, 1);

        int best = 1;

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < j; i++) {

                boolean ok = true;
                // check all rows for non-decreasing order
                for (int r = 0; r < rows; r++) {
                    if (strs[r].charAt(i) > strs[r].charAt(j)) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    keep[j] = Math.max(keep[j], keep[i] + 1);
                }
            }
            best = Math.max(best, keep[j]);
        }

        // minimum deletions = total columns - maximum kept columns
        return cols - best;
    }
}
