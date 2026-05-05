# ✨ Number of Paths With Sum Divisible by k — Explanation & Code ✨

> **Dynamic Programming looks scary? Don’t worry — this breakdown makes it crystal clear!**

---

## 🎯 **Intuition**

> We need the number of paths from **top-left** to **bottom-right** in a grid where  
> the **sum of values along the path is divisible by `k`**.  
>
> We can only move **right** or **down**.  
>
> This suggests a **2D DP grid**, but since divisibility depends on the **remainder mod k**,  
> each cell must track **k possible remainders**.

---

## 🎯 **What I want to do (high-level goal)**

> - For every cell `(r, c)`, store how many ways we can reach it with  
>   **each possible remainder** `0...k-1`.  
> - Combine paths from **top** and **left**.  
> - Transition the remainder using:  
>   `newRemainder = (oldRemainder + grid[r][c]) % k`  
> - At the end, return the number of ways to reach the destination cell  
>   with **remainder 0**.

---

## 🧠 **Why this works**

> - Every path has a cumulative sum → the sum’s modulo `k` determines whether it's valid.  
> - The modulo behaves nicely under addition:  
>   `(a + b) % k = ((a % k) + (b % k)) % k`  
> - This means we never need full sums — **tracking remainders alone is enough**.  
> - Since every cell has at most **two incoming directions** (top, left),  
>   we simply add contributions of all valid remainders from those directions.  
> - Using a 3D DP table `dp[r][c][rem]` ensures we account for every path possibility.

---

## 🔧 **Approach (step-by-step)**

> 1. Create a 3D DP table:  
>    `dp[rows][cols][k]`  
>    where `dp[r][c][rem] = number of ways to reach (r, c) with sum % k = rem`.  
>
> 2. Initialize starting point:  
>    remainder = `grid[0][0] % k`  
>    → `dp[0][0][remainder] = 1`  
>
> 3. Fill the **first row** (can only move right).  
>
> 4. Fill the **first column** (can only move down).  
>
> 5. For every other cell:  
>    - For each possible remainder `rem` from `0 to k-1`:  
>      - Compute new remainder using current cell value.  
>      - Add ways from **top** and **left**.  
>
> 6. Final answer is:  
>    `dp[lastRow][lastCol][0]`  
>    because we need paths whose total sum is divisible by `k`.

---

## 🔍 **Dry Run Example (conceptual)**

> Suppose `k = 3`, and at some cell `(r,c)` we want remainder = 1.  
> If from top we can arrive with:  
> - remainder 0 → adding cell value 1 gives `(0 + 1) % 3 = 1`  
> - remainder 2 → adding cell value 2 gives `(2 + 2) % 3 = 1`  
>
> Then both contribute to `dp[r][c][1]`.  
>
> This logic happens for every cell, every remainder.

---

## 📊 **Complexity**

> - **Time Complexity:** `O(rows * cols * k)`  
> - **Space Complexity:** `O(rows * cols * k)`  
>   (can be optimized, but this is the clean direction-based DP)

---

## 💻 **Code**

```java

class Solution {
    // Standard modulo for large number results to prevent overflow
    private static final int MOD = 1_000_000_007;

    public int numberOfPaths(int[][] grid, int k) {
        int rows = grid.length;
        int cols = grid[0].length;

        /**
         * 3D DP Array definition:
         * dp[r][c][rem] stores the number of paths from (0,0) to (r,c) 
         * such that the current sum of elements has a remainder 'rem' when divided by 'k'.
         */
        int[][][] dp = new int[rows][cols][k];

        // Base case: Starting cell (0,0)
        // Its remainder is simply the value of the cell mod k
        dp[0]0[0] % k] = 1;

        // Step 1: Initialize the first row
        // At any cell in the first row, you can ONLY arrive from the left (col - 1)
        for (int col = 1; col < cols; col++) {
            int val = grid[0][col];
            for (int rem = 0; rem < k; rem++) {
                if (dp[0][col - 1][rem] > 0) {
                    // Current remainder = (previous remainder + current cell value) % k
                    int nxt = (rem + val) % k;
                    dp[0][col][nxt] = (dp[0][col][nxt] + dp[0][col - 1][rem]) % MOD;
                }
            }
        }

        // Step 2: Initialize the first column
        // At any cell in the first column, you can ONLY arrive from above (row - 1)
        for (int row = 1; row < rows; row++) {
            int val = grid[row][0];
            for (int rem = 0; rem < k; rem++) {
                if (dp[row - 1][0][rem] > 0) {
                    int nxt = (rem + val) % k;
                    dp[row][0][nxt] = (dp[row][0][nxt] + dp[row - 1][0][rem]) % MOD;
                }
            }
        }

        // Step 3: Fill the rest of the grid
        // For internal cells, we can arrive from either the TOP or the LEFT
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                int cell = grid[r][c];

                for (int rem = 0; rem < k; rem++) {
                    // Pre-calculate the new remainder for this cell based on incoming 'rem'
                    int newRem = (rem + cell) % k;

                    // Option A: Path coming from the cell directly ABOVE
                    if (dp[r - 1][c][rem] > 0) {
                        dp[r][c][newRem] = (dp[r][c][newRem] + dp[r - 1][c][rem]) % MOD;
                    }

                    // Option B: Path coming from the cell directly to the LEFT
                    if (dp[r][c - 1][rem] > 0) {
                        dp[r][c][newRem] = (dp[r][c][newRem] + dp[r][c - 1][rem]) % MOD;
                    }
                }
            }
        }

        /**
         * Return the result at the target cell (bottom-right).
         * We specifically look for the bucket where the remainder is 0,
         * indicating the total sum is divisible by k.
         */
        return dp[rows - 1][cols - 1][0];
    }
}
