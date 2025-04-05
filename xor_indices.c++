#include <vector>
#include <numeric> // For std::accumulate

class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        int totalXORSum = 0;
        int n = nums.size();

        // Iterate through all possible subsets using bit manipulation
        for (int i = 0; i < (1 << n); ++i) {
            int currentXORSum = 0;
            for (int j = 0; j < n; ++j) {
                // If the j-th bit of i is set, include nums[j] in the current subset
                if ((i >> j) & 1) {
                    currentXORSum ^= nums[j];
                }
            }
            totalXORSum += currentXORSum;
        }
        return totalXORSum;
    }
};