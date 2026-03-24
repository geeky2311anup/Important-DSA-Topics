// 💎 This is a classic Prefix Sum + Pruning Based Matrix Problem

// ## 🧩 Overview

// ```Problem_Explanation []
// You are given a 2D integer grid.

// A square sub-matrix is called a *Magic Square* if:
// ➤ All row sums are equal
// ➤ All column sums are equal
// ➤ Both diagonals have the same sum

// Your task is to find the **largest possible size**
// (side length) of a magic square inside the grid.
// ```

// ```📥_Input_Output []
// 📥 Input
// grid → 2D integer matrix

// 📤 Output
// Return an integer representing the maximum
// side length of a valid magic square
// ```

// ## 😎 Think Like

// ```❌_What_Will_NOT_Work []
// 🚫 Brute force checking every square cell-by-cell
// → O(N⁴) time → TLE

// 🚫 Recalculating row and column sums repeatedly
// → Redundant computation

// 🚫 Checking smaller squares first
// → No pruning, wasted effort
// ```

// ```✅_Correct_Strategy []
// ➤ Precompute prefix sums for rows and columns
// ➤ Fix top-left corner of square
// ➤ Try larger squares first to prune early
// ➤ Validate rows & columns in O(1)
// ➤ Validate diagonals manually
// ➤ Track maximum size
// ```

// ## ☝️ Lets Visualise

// ```📊_Visualisation []
// Grid:
//
// 7  1  4  5
// 2  5  1  6
// 1  5  4  3
// 1  2  7  3
//
// Consider top-left at (0,0):
//
// 7  1  4
// 2  5  1
// 1  5  4
//
// Row sums  = 12
// Col sums  = 12
// Diagonals = 12
//
// ✔ Valid 3×3 magic square
// ```

/* ```🧪_Dry_Run []
   Step 1: Precompute prefix sums for rows and columns
   Step 2: Choose top-left corner (r, c)
   Step 3: Determine largest possible square size
   Step 4: Check each row sum, column sum, main diagonal, anti-diagonal
   Step 5: If all equal → update maxSize
*/ 

// ---
// # **Algorithm (Sorting Optimization + Rectangle Intersection Logic)**

// In this approach, we first **group all rectangle coordinates using zip and sort them**. Sorting helps optimize
// the intersection checking process because it allows **early termination** when no further overlapping rectangles
// are possible. Although sorting is optional, skipping it means we must check **all possible rectangle pairs**.
// When sorting is applied, we can safely use the break condition `if (overlapX < 0 && overlapY < 0) break;` to
// stop unnecessary comparisons.

// We are given two rectangles defined by four coordinates each: **Rectangle A (ax1, ay1, ax2, ay2)** and
// **Rectangle B (bx1, by1, bx2, by2)**. To find the overlapping region, we compute the overlap on the X-axis as
// **overlapX = min(ax2, bx2) − max(ax1, bx1)** and the overlap on the Y-axis as
// **overlapY = min(ay2, by2) − max(ay1, by1)**. If both **overlapX and overlapY are negative**, it means there is
// **no intersection** between the current rectangle and any upcoming rectangles (when sorted), so we immediately
// move to the next rectangle.

// If both **overlapX and overlapY are positive**, an overlapping region exists. Inside this region, the largest
// possible square can be formed by taking the **minimum of overlapX and overlapY** as the square’s side length,
// since all sides of a square are equal. We continuously update a variable `res` to store the **maximum side
// length found so far**. After all rectangle pairs are processed, the final answer is obtained by computing the
// **maximum square area as `res * res`**. This method ensures **efficient intersection handling**, **reduced
// unnecessary comparisons**, and **optimal performance when sorting optimization is applied**.

// ---
// ```java []
class Solution {

    // Main function
    public int largestMagicSquare(int[][] mat) {
        int R = mat.length;
        int C = mat[0].length;
        int[][] rowSum = new int[R][C];
        int[][] colSum = new int[R][C];
        for (int r = 0; r < R; r++) {
            rowSum[r][0] = mat[r][0];
            for (int c = 1; c < C; c++)
                rowSum[r][c] = rowSum[r][c - 1] + mat[r][c];
        }
        for (int c = 0; c < C; c++) {
            colSum[0][c] = mat[0][c];
            for (int r = 1; r < R; r++)
                colSum[r][c] = colSum[r - 1][c] + mat[r][c];
        }

        int maxSize = 1;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int maxPossible = Math.min(R - r, C - c);
                for (int size = maxPossible; size > maxSize; size--) {
                    if (isMagicSquare(r, c, size, mat, rowSum, colSum)) {
                        maxSize = size;
                        break;
                    }
                }
            }
        }
        return maxSize;
    }

    private boolean isMagicSquare(int sr, int sc, int size, int[][] mat, int[][] rowSum, int[][] colSum) {
        int expected = rowSum[sr][sc + size - 1] - (sc > 0 ? rowSum[sr][sc - 1] : 0);
        for (int r = sr; r < sr + size; r++) {
            int sum = rowSum[r][sc + size - 1] - (sc > 0 ? rowSum[r][sc - 1] : 0);
            if (sum != expected) return false;
        }
        for (int c = sc; c < sc + size; c++) {
            int sum = colSum[sr + size - 1][c] - (sr > 0 ? colSum[sr - 1][c] : 0);
            if (sum != expected) return false;
        }
        int diag1 = 0;
        for (int k = 0; k < size; k++)
            diag1 += mat[sr + k][sc + k];
        if (diag1 != expected) return false;
        int diag2 = 0;
        for (int k = 0; k < size; k++)
            diag2 += mat[sr + size - 1 - k][sc + k];
        return diag2 == expected;
    }
}
// ```

// ---
// ```cpp []
#include <vector>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& mat) {
        int R = mat.size();
        int C = mat[0].size();
        vector<vector<int>> rowSum(R, vector<int>(C));
        vector<vector<int>> colSum(R, vector<int>(C));

        for(int r = 0; r < R; r++) {
            rowSum[r][0] = mat[r][0];
            for(int c = 1; c < C; c++)
                rowSum[r][c] = rowSum[r][c-1] + mat[r][c];
        }

        for(int c = 0; c < C; c++) {
            colSum[0][c] = mat[0][c];
            for(int r = 1; r < R; r++)
                colSum[r][c] = colSum[r-1][c] + mat[r][c];
        }

        int maxSize = 1;
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                int maxPossible = min(R-r, C-c);
                for(int size = maxPossible; size > maxSize; size--) {
                    if(isMagicSquare(r, c, size, mat, rowSum, colSum)) {
                        maxSize = size;
                        break;
                    }
                }
            }
        }
        return maxSize;
    }

private:
    bool isMagicSquare(int sr, int sc, int size, vector<vector<int>>& mat,
                       vector<vector<int>>& rowSum, vector<vector<int>>& colSum) {
        int expected = rowSum[sr][sc+size-1] - (sc>0 ? rowSum[sr][sc-1] : 0);
        for(int r = sr; r < sr+size; r++) {
            int sum = rowSum[r][sc+size-1] - (sc>0 ? rowSum[r][sc-1] : 0);
            if(sum != expected) return false;
        }
        for(int c = sc; c < sc+size; c++) {
            int sum = colSum[sr+size-1][c] - (sr>0 ? colSum[sr-1][c] : 0);
            if(sum != expected) return false;
        }
        int diag1=0;
        for(int k=0;k<size;k++) diag1 += mat[sr+k][sc+k];
        if(diag1 != expected) return false;
        int diag2=0;
        for(int k=0;k<size;k++) diag2 += mat[sr+size-1-k][sc+k];
        return diag2 == expected;
    }
};
