Intuition
The key idea is to treat each row as the base of a histogram.
From the diagram:

Each cell accumulates vertical heights of consecutive 1’s.
Example: after Row 2, heights become [2,1,0,1,...] (as shown).
Instead of keeping column order fixed, we can rearrange columns.
Why?
Because we are allowed to reorder columns → we can maximize width.

So for each row:

Build histogram heights (cumulative 1’s).
Sort heights → gives best arrangement.
Try all possible widths and compute max area.
This is exactly what the diagram shows:

Original heights → [3,1,2,3]
Sorted heights → [1,2,3,3]
Then compute areas from right side.
Approach
ChatGPT Image Mar 17, 2026, 06_38_20 AM.png

ChatGPT Image Mar 17, 2026, 06_37_51 AM.png

Step-by-step (aligned with diagram):

Build Histogram Heights
From the first diagram:

Row 1 → [1,0,1,0,...]
Row 2 → add previous row → [2,1,0,1,...]
Row 3 → continue accumulation
Formula:
if grid[r][c] == 1:
grid[r][c] += grid[r-1][c]

Sort Heights
From second diagram:
Original: [3,1,2,3]
Sorted: [1,2,3,3]

Sorting allows grouping tallest columns together.

Compute Max Area
Iterate from largest height:
width = number of columns to the right

Example (diagram):
heights = [1,2,3,3]

i=3 → height=3, width=1 → area=3
i=2 → height=3, width=2 → area=6
i=1 → height=2, width=3 → area=6
i=0 → height=1, width=4 → area=4

Max = 6 (or 12 in full example)

Track global maximum.

This matches the diagram’s:
"Area = height × width"

Complexity
Time complexity:
O(rows * cols * log(cols))
(sorting each row)

Space complexity:
O(cols)
(for heights array)

Code
class Solution {
    public int largestSubmatrix(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {

            // Build height histogram (as shown in first diagram)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && r > 0) {
                    grid[r][c] = grid[r][c] + grid[r - 1][c];
                }
            }

            // Copy heights for sorting (simulate column rearrangement)
            int[] heights = new int[cols];
            for (int i = 0; i < cols; i++) {
                heights[i] = grid[r][i];
            }

            // Sort heights (like "Sorted Heights" diagram)
            Arrays.sort(heights);

            // Compute max area (right → left)
            for (int i = cols - 1; i >= 0; i--) {
                int width = cols - i; // number of columns used
                int area = heights[i] * width;

                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }

        return maxArea;
    }
}
