# 🤔 Am I the only one who checked **Magic Squares** without any fancy tricks? 😌✨

---

## 🧩 Problem Name  
**Magic Squares In Grid** (LeetCode)

---

## 🎯 Intuition — what you want to do  
> You are given a 2D grid.  
>  
> Your task is to count how many **3×3 subgrids** are **magic squares**.
>
> A **3×3 magic square** must satisfy:
> - It contains **all numbers from 1 to 9 exactly once**
> - Every **row sum**, **column sum**, and **both diagonals** are equal

So the idea is simple:
> 👉 Slide a **3×3 window** over the grid and **validate each window**.

No shortcuts, no math tricks — just careful checking.

---

## 🎯 What you want to do (high-level goal / why)  
> - For every possible 3×3 subgrid:
>   - Check number range `[1..9]`
>   - Check uniqueness (no duplicates)
>   - Check row sums
>   - Check column sums
>   - Check diagonal sums
> - Count how many subgrids pass all checks

Why brute-force?
> Because the grid is small enough and **each 3×3 check is constant time**.

---

## 🧠 Why this works  
> - A 3×3 magic square has **very strict conditions**
> - If **any single rule fails**, it is not magic
> - Total work = number of 3×3 windows × constant checks  
> - This guarantees correctness without overthinking

---

## 🔧 Approach (matching the implementation)

### 1) Iterate over all possible 3×3 subgrids  
> - Top-left corner `(r, c)`  
> - Valid range:
>   - `r = 0 .. rows-3`
>   - `c = 0 .. cols-3`

---

### 2) Validate each 3×3 using `checkMagic(...)`

Inside validation:

#### ✅ Step 1: Check values and uniqueness  
> - All numbers must be between `1` and `9`
> - Each number must appear **exactly once**
> - Use a boolean array `used[1..9]`

---

#### ✅ Step 2: Fix a target sum  
> - Take the sum of the **first row**
> - Every row, column, and diagonal must match this sum

---

#### ✅ Step 3: Check all rows and columns  
> - 3 rows
> - 3 columns

If any mismatch → ❌ not magic

---

#### ✅ Step 4: Check both diagonals  
> - Main diagonal
> - Anti-diagonal

If both match the target → ✅ magic square

---

## 🔍 What each method contributes

### `numMagicSquaresInside(...)`
> - Slides the 3×3 window over the grid
> - Calls `checkMagic` for each position
> - Counts valid magic squares

---

### `checkMagic(...)`
> - Performs **all validation logic**
> - Ensures correctness of:
>   - Value range
>   - Uniqueness
>   - Row sums
>   - Column sums
>   - Diagonal sums

---

## 🧪 Dry Run (small example)

Grid:
4 3 8
9 5 1
2 7 6

pgsql
Copy code

- Numbers: 1..9 ✔
- Rows sum to 15 ✔
- Columns sum to 15 ✔
- Diagonals sum to 15 ✔

➡ Count this subgrid ✅

---

## 📊 Complexity

> - **Time Complexity:** `O(rows × cols)`  
>   (each 3×3 check is constant time)
>
> - **Space Complexity:** `O(1)`  
>   (fixed-size boolean array)

---

## 💻 Code

```java
class Solution {

    // Helper function to check if the 3x3 subgrid starting at (row, col)
    // forms a valid magic square
    private boolean checkMagic(int[][] mat, int row, int col) {

        // In a magic square, all rows, columns, and diagonals
        // must have the same sum.
        // We take the first row as the target sum.
        int target = mat[row][col] 
                   + mat[row][col + 1] 
                   + mat[row][col + 2];

        // Boolean array to ensure numbers 1–9 appear exactly once
        // Index 0 is unused
        boolean[] used = new boolean[10];

        // Step 1: Check if all numbers are between 1 and 9
        // and ensure there are no duplicates
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = mat[row + i][col + j];

                // If number is out of range or already used, not magic
                if (val < 1 || val > 9 || used[val]) 
                    return false;

                used[val] = true;
            }
        }

        // Step 2: Check all row sums and column sums
        for (int k = 0; k < 3; k++) {

            // Sum of kth row
            int rowSum = mat[row + k][col] 
                       + mat[row + k][col + 1] 
                       + mat[row + k][col + 2];

            // Sum of kth column
            int colSum = mat[row][col + k] 
                       + mat[row + 1][col + k] 
                       + mat[row + 2][col + k];

            // If any row or column sum differs from target, not magic
            if (rowSum != target || colSum != target) 
                return false;
        }

        // Step 3: Check both diagonals

        // Main diagonal: top-left to bottom-right
        int diag1 = mat[row][col] 
                  + mat[row + 1][col + 1] 
                  + mat[row + 2][col + 2];

        // Anti-diagonal: top-right to bottom-left
        int diag2 = mat[row][col + 2] 
                  + mat[row + 1][col + 1] 
                  + mat[row + 2][col];

        // If diagonal sums differ, not magic
        if (diag1 != target || diag2 != target) 
            return false;

        // If all checks pass, it is a magic square
        return true;
    }

    public int numMagicSquaresInside(int[][] grid) {

        int rows = grid.length;
        int cols = grid[0].length;
        int count = 0;

        // We check every possible 3x3 subgrid
        // So we iterate until rows-3 and cols-3
        for (int r = 0; r <= rows - 3; r++) {
            for (int c = 0; c <= cols - 3; c++) {

                // If this 3x3 block is a magic square, increment count
                if (checkMagic(grid, r, c)) {
                    count++;
                }
            }
        }

        // Return total number of magic squares found
        return count;
    }
}

