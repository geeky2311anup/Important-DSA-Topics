#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilings(int n) {

        // Large modulo value to avoid integer overflow
        const int MOD = 1000000007;

        // Base cases:
        // For n = 1 → only one vertical domino
        // For n = 2 → either two vertical or two horizontal dominoes
        if (n <= 2) return n;

        // dp[i]:
        // Number of ways to FULLY tile a 2 × i board
        vector<long long> dp(n + 1, 0);

        // gap[i]:
        // Number of ways to tile a 2 × i board such that
        // exactly ONE cell is missing (creating a "gap")
        // This represents partial tilings used to build future states
        vector<long long> gap(n + 1, 0);

        // ---- Initialization ----

        // An empty board counts as one valid tiling
        dp[0] = 1;

        // Only vertical domino fits
        dp[1] = 1;

        // Either two vertical or two horizontal dominoes
        dp[2] = 2;

        // Partial tiling base cases:
        // For width 1 → one way to leave a gap using a tromino
        gap[1] = 1;

        // For width 2 → two possible partial gap configurations
        gap[2] = 2;

        // ---- Build DP for larger widths ----
        for (int i = 3; i <= n; i++) {

            // FULL tiling dp[i] can be formed by:
            //
            // 1. Placing a vertical domino at the end of dp[i-1]
            // 2. Placing two horizontal dominoes at the end of dp[i-2]
            // 3. Filling a gap from gap[i-2] using L-shaped trominoes
            //    (two orientations → multiply by 2)
            dp[i] = (
                dp[i - 1] +
                dp[i - 2] +
                2 * gap[i - 2]
            ) % MOD;

            // PARTIAL tiling gap[i] can be formed by:
            //
            // 1. Extending an existing gap from gap[i-1]
            // 2. Creating a new gap by placing a tromino on dp[i-1]
            gap[i] = (
                gap[i - 1] +
                dp[i - 1]
            ) % MOD;
        }

        // Final answer:
        // Number of ways to completely tile a 2 × n board
        return dp[n];
    }
};
