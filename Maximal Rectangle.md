# 85. Maximal Rectangle

## Problem Summary

You are given a binary matrix filled with `'0'` and `'1'`.

Your task is to find the area of the **largest rectangle** containing only `'1'`s.

The rectangle must be:
- Axis-aligned
- Fully filled with `'1'`
- Contiguous

Just rectangles. No diagonals. No mercy.

---

## Core Idea

A rectangle of `1`s can be seen as:
- Choosing a **row as the bottom**
- Treating each column as a **histogram height**
- Expanding left while maintaining the minimum height

This solution:
- Builds heights of consecutive `1`s column-wise
- For each cell, treats it as the **right boundary** of a rectangle
- Expands left to compute the maximum area ending at that cell

Brute-force flavored.
Still valid.
Still passes.

---

## Preprocessing: Height Matrix

We build a matrix `h` where:

h[i][j] = number of consecutive `1`s ending at row `i` in column `j`

This converts each row into a histogram.

---

## DP Meaning

Let:

dp[i][j] = maximum rectangle area  
with bottom-right corner at cell `(i, j)`

The final answer is the maximum value in `dp`.

---

## Algorithm Steps

1. Initialize height and dp matrices
2. Fill the first row separately
3. Build heights for all rows
4. For each cell `(i, j)` containing `'1'`:
   - Expand left from `j` to `0`
   - Track the minimum height seen
   - Compute area = height × width
   - Store the maximum area found
5. Keep updating the global maximum

---

## Java Implementation

(Indented to stay inside the markdown block)

    class Solution {
        public int maximalRectangle(char[][] matrix) {
            int n = matrix.length;
            int m = matrix[0].length;

            int[][] h = new int[n][m];
            int[][] dp = new int[n][m];

            int ans = 0;

            // First row initialization
            for (int j = 0; j < m; j++) {
                if (matrix[0][j] == '1') {
                    h[0][j] = 1;
                    dp[0][j] = (j > 0 ? dp[0][j - 1] : 0) + 1;
                    ans = Math.max(ans, dp[0][j]);
                }
            }

            // Build height matrix
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == '1') {
                        h[i][j] = h[i - 1][j] + 1;
                    } else {
                        h[i][j] = 0;
                    }
                }
            }

            // DP computation
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == '1') {
                        int width = 1;
                        int minHeight = h[i][j];
                        int maxArea = minHeight;

                        for (int k = j - 1; k >= 0 && matrix[i][k] == '1'; k--) {
                            minHeight = Math.min(minHeight, h[i][k]);
                            width++;
                            maxArea = Math.max(maxArea, minHeight * width);
                        }

                        dp[i][j] = maxArea;
                        ans = Math.max(ans, dp[i][j]);
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }

            return ans;
        }
    }

---

## Complexity Analysis

Let:
- n = number of rows
- m = number of columns

Time Complexity:
O(n × m × m)  
Worst case due to left expansion for each cell.

Space Complexity:
O(n × m)  
For height and dp matrices.

---

## Final Thought

This solution is not optimal.
It is honest.

It brute-forces rectangles intelligently using heights,
not stacks, not magic.

If monotonic stacks are a scalpel,
this approach is a hammer.

Both work.
One just hits harder.
