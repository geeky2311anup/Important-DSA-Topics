#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <cmath>
#include <functional>


class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string low = to_string(start);
        string high = to_string(finish);
        int n = high.size();
        low = string(n - low.size(), '0') + low; // Align digits
        int prefixLength = n - s.size();         // Prefix length

        vector<long long> memo(n, -1);
        function<long long(int, bool, bool)> countPowerful =
            [&](int index, bool tightLower, bool tightUpper) -> long long {
            // Base case: Reached the end of the numbers
            if (index == n) {
                return 1;
            }

            // Memoization: If the result for this state is already computed and no tight constraints
            if (!tightLower && !tightUpper && memo[index] != -1) {
                return memo[index];
            }

            long long result = 0;
            int lowerBound = tightLower ? (low[index] - '0') : 0;
            int upperBound = tightUpper ? (high[index] - '0') : 9;

            if (index < prefixLength) {
                // Iterate through possible digits for the prefix
                for (int digit = lowerBound; digit <= min(upperBound, limit); ++digit) {
                    result += countPowerful(index + 1, tightLower && (digit == lowerBound), tightUpper && (digit == upperBound));
                }
            } else {
                // The current digit must match the corresponding digit in 's'
                int requiredDigit = s[index - prefixLength] - '0';
                if (lowerBound <= requiredDigit && requiredDigit <= min(upperBound, limit)) {
                    result = countPowerful(index + 1, tightLower && (requiredDigit == lowerBound), tightUpper && (requiredDigit == upperBound));
                }
            }

            // Store the result in memoization table if no tight constraints
            if (!tightLower && !tightUpper) {
                memo[index] = result;
            }
            return result;
        };

        return countPowerful(0, true, true);
    }
};