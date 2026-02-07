class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int total = 0;

        // Step 1: Add fruits collected along the main diagonal (i, i)
        // This represents the fruits collected by the first path.
        for (int i = 0; i < n; ++i) {
            total += fruits[i][i];
        }

        // Helper function to calculate the maximum fruit collection
        // for a path that starts at the top-right corner (0, n-1)
        // and ends at the bottom-right corner (n-1, n-1).
        auto getMaxPath = [&](vector<vector<int>>& grid) {
            // prev[j] = maximum fruits collected to reach column j
            vector<int> prev(n, INT_MIN), curr(n, INT_MIN);

            // Starting position at row 0, column (n-1)
            prev[n - 1] = grid[0][n - 1];

            // Iterate through rows (excluding first and last)
            for (int i = 1; i < n - 1; ++i) {
                // Only consider valid column range
                for (int j = max(n - 1 - i, i + 1); j < n; ++j) {

                    // Choose the best previous position
                    int bestPrev = prev[j];
                    if (j - 1 >= 0) bestPrev = max(bestPrev, prev[j - 1]);
                    if (j + 1 < n) bestPrev = max(bestPrev, prev[j + 1]);

                    // Update current cell value
                    curr[j] = bestPrev + grid[i][j];
                }

                // Move current results to previous for next iteration
                swap(prev, curr);
            }

            // Return the result at bottom-right column
            return prev[n - 1];
        };

        // Step 2: Add the maximum path from top-right to bottom-right
        total += getMaxPath(fruits);

        // Step 3: Transpose the grid
        // This Compute maximum path for the symmetric case
        // (left side path equivalent)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(fruits[i][j], fruits[j][i]);
            }
        }

        // Step 4: Add the second maximum path after transpose
        total += getMaxPath(fruits);

        return total;
    }
};
