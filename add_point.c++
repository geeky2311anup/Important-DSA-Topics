#include <iostream>
#include <vector>

class Solution {
public:
    int countSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        
        int count = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == 2 * (long long)nums[i - 1] + 2 * (long long)nums[i + 1]) {
                ++count;
            }
        }
        return count;
    }
};