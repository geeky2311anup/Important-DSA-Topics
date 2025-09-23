#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxCollectedFruits(vector<vector<int>>& fruits) {
            int n = fruits.size();
            int total = 0;
    
            // Add diagonal fruits (i, i)
            for (int i = 0; i < n; ++i) {
                total += fruits[i][i];
            }
    
            // Helper to calculate maximum sum path ending at column (n-1)
            auto getMaxPath = [&](vector<vector<int>>& grid) {
                vector<int> prev(n, INT_MIN), curr(n, INT_MIN);
                prev[n - 1] = grid[0][n - 1];  // Starting from top row, col (n-1)
    
                for (int i = 1; i < n - 1; ++i) {
                    for (int j = max(n - 1 - i, i + 1); j < n; ++j) {
                        int bestPrev = prev[j];
                        if (j - 1 >= 0) bestPrev = max(bestPrev, prev[j - 1]);
                        if (j + 1 < n) bestPrev = max(bestPrev, prev[j + 1]);
                        curr[j] = bestPrev + grid[i][j];
                    }
                    swap(prev, curr);
                }
                return prev[n - 1];
            };
    
            total += getMaxPath(fruits);
    
            // Transpose the grid (swap fruits[i][j] and fruits[j][i] for i < j)
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    swap(fruits[i][j], fruits[j][i]);
                }
            }
    
            total += getMaxPath(fruits);
    
            return total;
        }
    };
    