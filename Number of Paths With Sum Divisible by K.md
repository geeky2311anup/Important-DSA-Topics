# 😏 Is it just grid DP… or **modulo-state DP flexing quietly**? 🤔✨
*(Counting valid paths without tracking huge sums)*

---

## 🎯 Problem Name
**Number of Paths With Sum Divisible by K**

---

## 🎯 Intuition — what you want to do
> You are given a grid of integers where:
> - You start from the **top-left** cell
> - You can move **only right or down**
> - You must reach the **bottom-right** cell
>
> Your task:
> 👉 **Count how many paths have total sum divisible by `k`**
> Return the answer modulo `1e9 + 7`.

Brute force?
> ❌ Impossible — number of paths grows exponentially.

So what’s the trick?
> 👉 Track **sum modulo `k`**, not the actual sum.

---

## 🎯 What you want to do (high-level goal / why)
> - Process the grid **cell by cell**
> - For each cell, track:
>   - how many ways reach this cell
>   - with each possible **remainder modulo `k`**
> - Build paths incrementally using DP
> - In the end, count paths whose remainder is `0`

Why this works:
> Divisibility depends **only on remainder**, not on the full sum.

---

## 🧠 Why this works
> - Modulo arithmetic preserves divisibility:
>   `(a + b) % k = ((a % k) + (b % k)) % k`
> - Path sums can grow very large, but remainders stay bounded
> - There are only `k` possible states per cell

This is a classic **state-compression DP on modulo values**.

---

## 🔧 Approach (matching the implementation)

### 1) DP state definition
> `dp[r][c][rem]` = number of ways to reach cell `(r, c)`
> such that the path sum modulo `k` equals `rem`.

---

### 2) Base case
At the starting cell `(0,0)`:
> The initial remainder is `grid[0][0] % k`

So we initialize:
> `dp[0][0][grid[0][0] % k] = 1`

---

### 3) State transitions
To reach a cell `(r, c)`:
- You can come from **top** `(r-1, c)`
- Or from **left** `(r, c-1)`

For each previous remainder `rem`:
> `newRem = (rem + grid[r][c]) % k`

Accumulate ways for `newRem`.

---

### 4) Boundary handling
- First row → only from the left
- First column → only from the top

Handled separately to avoid index checks.

---

### 5) Final answer
At the destination cell `(rows-1, cols-1)`:
> We want paths where `sum % k == 0`

So the answer is:
> `dp[rows-1][cols-1][0]`

---

## 🧪 Dry Run (small example)

Grid:
[
 [5, 2],
 [1, 4]
]
k = 3

Paths:
- Right → Down: sum = 11 → 11 % 3 = 2 ❌
- Down → Right: sum = 10 → 10 % 3 = 1 ❌

Answer = **0**

---

## 📊 Complexity
> **Time Complexity:** `O(rows × cols × k)`
> **Space Complexity:** `O(rows × cols × k)`

---

## 💻 Code

    class Solution {
    // Constant for modulo operation to avoid overflow
    private static final int MOD = 1_000_000_007;

    public int numberOfPaths(int[][] grid, int k) {
        int rows = grid.length;
        int cols = grid[0].length;

        // dp[r][c][rem] = number of ways to reach cell (r,c)
        // such that the sum of the path % k = rem
        int[][][] dp = new int[rows][cols][k];

        // Base case: starting cell
        dp[0][0][grid[0][0] % k] = 1;

        // Fill first row (can only come from left)
        for (int c = 1; c < cols; c++) {
            int val = grid[0][c];
            for (int rem = 0; rem < k; rem++) {
                // If there are ways to reach previous cell with remainder 'rem'
                if (dp[0][c - 1][rem] > 0) {
                    int nxt = (rem + val) % k; // new remainder after adding current cell

                    // Add ways from left cell
                    dp[0][c][nxt] =
                        (dp[0][c][nxt] + dp[0][c - 1][rem]) % MOD;
                }
            }
        }

        // Fill first column (can only come from top)
        for (int r = 1; r < rows; r++) {
            int val = grid[r][0];
            for (int rem = 0; rem < k; rem++) {
                if (dp[r - 1][0][rem] > 0) {
                    int nxt = (rem + val) % k;

                    // Add ways from top cell
                    dp[r][0][nxt] =
                        (dp[r][0][nxt] + dp[r - 1][0][rem]) % MOD;
                }
            }
        }

        // Fill the rest of the grid
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                int cell = grid[r][c];

                for (int rem = 0; rem < k; rem++) {
                    int newRem = (rem + cell) % k;

                    // Add ways coming from the top cell
                    dp[r][c][newRem] =
                        (dp[r][c][newRem] + dp[r - 1][c][rem]) % MOD;

                    // Add ways coming from the left cell
                    dp[r][c][newRem] =
                        (dp[r][c][newRem] + dp[r][c - 1][rem]) % MOD;
                }
            }
        }

        // Final answer: number of paths where sum % k == 0
        return dp[rows - 1][cols - 1][0];
    }
}

---

## 🧠 One-line takeaway
> Track path counts by modulo-`k` states instead of full sums, and build valid paths using DP transitions from top and left.
