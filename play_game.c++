#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lower_bound(std::vector<int>& nums, int low, int high, int element) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= element) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
          
           
            int low_idx = lower_bound(nums, i + 1, n - 1, lower - nums[i]);

         
            int high_idx = lower_bound(nums, i + 1, n - 1, upper - nums[i] + 1);
          ans += static_cast<long long>(high_idx - low_idx);
        }
        return ans;
    }
};