#include <vector>
#include <algorithm>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) {
            return 0;
        }

        int maxElement = *std::max_element(nums.begin(), nums.end());
        long long ans = 0;
        int start = 0;
        int maxElementsInWindow = 0;

        for (int end = 0; end < nums.size(); ++end) {
            if (nums[end] == maxElement) {
                maxElementsInWindow++;
            }
            while (maxElementsInWindow == k) {
                if (nums[start] == maxElement) {
                    maxElementsInWindow--;
                }
                start++;
            }
            ans += start;
        }
        return ans;
    }
};