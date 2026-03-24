class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;

        // row[i][j] = number of consecutive 1s ending at (i, j) in that row
        vector<vector<int>> row(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                // Build horizontal prefix of 1s
                if (j == 0) {
                    row[i][j] = mat[i][j];  // first column
                } else {
                    // If current cell is 1 → extend streak, else reset to 0
                    row[i][j] = (mat[i][j] == 0) ? 0 : row[i][j - 1] + 1;
                }

                // Now treat (i, j) as bottom-right corner of submatrices
                int cur = row[i][j];

                // Go upwards row by row to count valid submatrices
                for (int k = i; k >= 0; --k) {

                    // Take minimum width seen so far
                    // (limits rectangle width)
                    cur = min(cur, row[k][j]);

                    // If width becomes 0 → no valid rectangle possible
                    if (cur == 0) {
                        break;
                    }

                    // Add number of rectangles ending here
                    res += cur;
                }
            }
        }

        return res;
    }
};
