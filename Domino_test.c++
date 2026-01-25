#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        // Modulo value to prevent integer overflow
        const int MOD = 1000000007;

        // Base cases:
        // If n is 1 or 2, number of ways equals n
        if (n <= 2) return n;

        // dp[i] stores number of ways to completely tile a 2 x i board
        vector<long long> dp(n + 1, 0);

        // gap[i] stores number of ways to tile a 2 x i board
        // such that exactly one square is missing (a partial tiling)
        vector<long long> gap(n + 1, 0);

        // Initialization of base values
        dp[0] = 1;   // Empty board has one valid tiling
        dp[1] = 1;   // One vertical domino
        dp[2] = 2;   // Two vertical or two horizontal dominoes

        // Partial tiling base cases
        gap[1] = 1;
        gap[2] = 2;

        // Build the solution for larger boards
        for (int i = 3; i <= n; i++) {

            // Full tiling can be formed by:
            // 1. Adding a vertical domino to dp[i-1]
            // 2. Adding two horizontal dominoes to dp[i-2]
            // 3. Completing partial tilings from gap[i-2] in two orientations
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * gap[i - 2]) % MOD;

            // Partial tiling can be formed by:
            // 1. Extending a previous partial tiling
            // 2. Creating a new gap from a full tiling
            gap[i] = (gap[i - 1] + dp[i - 1]) % MOD;
        }

        // Result is the number of ways to fully tile 2 x n board
        return dp[n];
    }
};
