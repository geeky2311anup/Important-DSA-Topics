#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
    public:
        double soupServings(int n) {
            int m = ceil(n / 25.0);
            if (m >= 500) return 1.0; // Optimization
    
            vector<vector<double>> dp(m + 1, vector<double>(m + 1, 0.0));
            dp[0][0] = 0.5;
    
            for (int i = 1; i <= m; ++i) {
                dp[0][i] = 1.0;
                dp[i][0] = 0.0;
            }
    
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][j] = 0.25 * (
                        dp[max(0, i - 4)][j] +
                        dp[max(0, i - 3)][max(0, j - 1)] +
                        dp[max(0, i - 2)][max(0, j - 2)] +
                        dp[max(0, i - 1)][max(0, j - 3)]
                    );
                }
            }
    
            return dp[m][m];
        }
    };
    