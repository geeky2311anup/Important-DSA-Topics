#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Difference array to track range updates efficiently
        vector<int> diff(n + 1, 0);

        // Step 1: Apply all queries using difference array technique
        // Each query increases values in range [left, right] by 1
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];

            diff[left]++;        // Start increment from 'left'
            diff[right + 1]--;   // Stop increment after 'right'
        }

        // Step 2: Convert difference array into actual operation counts
        vector<int> ops(n, 0);   // ops[i] = number of operations affecting index i
        int currentOps = 0;

        for (int i = 0; i < n; ++i) {
            currentOps += diff[i];  // Build prefix sum
            ops[i] = currentOps;
        }

        // Step 3: Check if each element can be reduced to zero
        // nums[i] requires at least nums[i] operations
        for (int i = 0; i < n; ++i) {
            if (ops[i] < nums[i]) {
                // Not enough operations to make nums[i] zero
                return false;
            }
        }

        // If all elements can be reduced to zero
        return true;
    }
};
