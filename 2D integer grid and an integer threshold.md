# 💎This is a classic Prefix Sum + Binary Search (Pruning) Based Matrix Problem

  ## 🧩 Overview

  ```Problem_Explanation []
  You are given a 2D integer grid and an integer threshold.

  A square sub-matrix is considered valid if:
  ➤ The sum of all its elements is less than or equal to the given threshold.

  Your task is to find the **largest possible size**
  (side length) of such a square inside the grid.
  ```

  ```📥_Input_Output []
  📥 Input
  grid → 2D integer matrix
  threshold → integer limit

  📤 Output
  Return an integer representing the maximum
  side length of a valid square
  ```

  ## 😎 Think Like

  ```❌_What_Will_NOT_Work []
  🚫 Brute force checking every possible square
  → O(N⁴) time → TLE guaranteed

  🚫 Calculating square sums repeatedly
  → Same sub-matrix sums recomputed again and again

  🚫 Linear increase of square size
  → Misses opportunity to prune using binary search
  ```

  ```✅_Correct_Strategy []
  ➤ Use prefix sum matrix to compute square sum in O(1)

  ➤ Binary search on the side length of the square

  ➤ For each candidate length, check if *any* valid square exists

  ➤ If valid square exists → try bigger size
  ➤ Else → reduce size

  ➤ Final answer is the maximum valid length found
  ```

  ## ☝️ Lets Visualise

  ```📊_Visualisation []
  Grid:

  1  1  3  2
  4  3  2  1
  1  1  1  1
  2  2  2  2

  Threshold = 8

  Consider square of size 2:

  1  1
  4  3

  Sum = 9 ❌ exceeds threshold

  Consider another 2×2 square:

  1  1
  1  1

  Sum = 4 ✔ valid

  So size 2 is possible
  ```

  ```🧪_Dry_Run []
  Step 1: Build prefix sum matrix

  Step 2: Binary search on square size
          lo = 0, hi = min(rows, cols)

  Step 3: Pick mid as candidate size

  Step 4: Slide a window of size mid×mid
          using prefix sums to compute sum in O(1)

  Step 5:
    ✔ If any square sum ≤ threshold → move right
    ✘ Otherwise → move left

  Step 6: Return largest valid size
  ```

  ---
  # **Algorithm (Sorting Optimization + Rectangle Intersection Logic)**

  In this approach, we first **group all rectangle coordinates using zip and sort them**. Sorting helps optimize
  the intersection checking process because it allows **early termination** when no further overlapping rectangles
  are possible. Although sorting is optional, skipping it means we must check **all possible rectangle pairs**.
  When sorting is applied, we can safely use the break condition `if (overlapX < 0 && overlapY < 0) break;` to
  stop unnecessary comparisons.

  We are given two rectangles defined by four coordinates each: **Rectangle A (ax1, ay1, ax2, ay2)** and
  **Rectangle B (bx1, by1, bx2, by2)**. To find the overlapping region, we compute the overlap on the X-axis as
  **overlapX = min(ax2, bx2) − max(ax1, bx1)** and the overlap on the Y-axis as
  **overlapY = min(ay2, by2) − max(ay1, by1)**. If both **overlapX and overlapY are negative**, it means there is
  **no intersection** between the current rectangle and any upcoming rectangles (when sorted), so we immediately
  move to the next rectangle.

  If both **overlapX and overlapY are positive**, an overlapping region exists. Inside this region, the largest
  possible square can be formed by taking the **minimum of overlapX and overlapY** as the square’s side length,
  since all sides of a square are equal. We continuously update a variable `res` to store the **maximum side
  length found so far**. After all rectangle pairs are processed, the final answer is obtained by computing the
  **maximum square area as `res * res`**. This method ensures **efficient intersection handling**, **reduced
  unnecessary comparisons**, and **optimal performance when sorting optimization is applied**.

  ---
  ```java []
class Solution {

    int rows, cols;

    // Main function
    public int maxSideLength(int[][] grid, int limit) {

        rows = grid.length;
        cols = grid[0].length;

        // Prefix sum matrix
        int[][] prefix = new int[rows + 1][cols + 1];

        // Build prefix sums
        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                prefix[r][c] =
                        prefix[r - 1][c]
                      + prefix[r][c - 1]
                      - prefix[r - 1][c - 1]
                      + grid[r - 1][c - 1];
            }
        }

        int left = 0;
        int right = Math.min(rows, cols);
        int answer = 0;

        // Binary search on square size
        while (left <= right) {
            int size = left + (right - left) / 2;

            if (existsValidSquare(prefix, size, limit)) {
                answer = size;
                left = size + 1;
            } else {
                right = size - 1;
            }
        }

        return answer;
    }

    // Check if any square of given size satisfies threshold
    private boolean existsValidSquare(int[][] prefix, int size, int limit) {

        for (int r = size; r <= rows; r++) {
            for (int c = size; c <= cols; c++) {

                int squareSum =
                        prefix[r][c]
                      - prefix[r - size][c]
                      - prefix[r][c - size]
                      + prefix[r - size][c - size];

                if (squareSum <= limit) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

## ⏱ Complexity Analysis

Time Complexity: O(N² log N)
Space Complexity: O(N²)

---

Even **Iron Man** failed hundreds of times before building the suit.
Keep solving — one day your **bugs** become your superpower 💪
