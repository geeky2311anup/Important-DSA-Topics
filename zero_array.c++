#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // Using 'diff' instead of 'deltaArray'

        // Apply the queries using the difference array technique
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            diff[left]++;
            diff[right + 1]--;
        }

        // Calculate the prefix sum of the difference array
        vector<int> ops(n, 0); // 'ops' for operation counts
        int currentOps = 0;
        for (int i = 0; i < n; ++i) {
            currentOps += diff[i];
            ops[i] = currentOps;
        }

        // Check if the operations are sufficient to make the array zero
        for (int i = 0; i < n; ++i) {
            
            if (ops[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};