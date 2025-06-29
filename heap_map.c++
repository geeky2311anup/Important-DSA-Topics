#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numSubseq(std::vector<int>& nums, int target) {
        int n = nums.size();
        long long MOD = 1e9 + 7;

        std::sort(nums.begin(), nums.end());

        std::vector<long long> powersOf2(n);
        powersOf2[0] = 1;
        for (int i = 1; i < n; ++i) {
            powersOf2[i] = (powersOf2[i - 1] * 2) % MOD;
        }

        long long count = 0;
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                count = (count + powersOf2[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return static_cast<int>(count);
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1 = {3, 5, 6, 7};
    int target1 = 9;
    std::cout << "Example 1: " << sol.numSubseq(nums1, target1) << std::endl;

    std::vector<int> nums2 = {3, 3, 6, 8};
    int target2 = 10;
    std::cout << "Example 2: " << sol.numSubseq(nums2, target2) << std::endl;

    std::vector<int> nums3 = {2, 3, 3, 4, 6, 7};
    int target3 = 12;
    std::cout << "Example 3: " << sol.numSubseq(nums3, target3) << std::endl;

    std::vector<int> nums_single = {5};
    int target_single = 10;
    std::cout << "Single element satisfies: " << sol.numSubseq(nums_single, target_single) << std::endl;

    std::vector<int> nums_single_fail = {10};
    int target_single_fail = 5;
    std::cout << "Single element fails: " << sol.numSubseq(nums_single_fail, target_single_fail) << std::endl;

    std::vector<int> nums_empty = {};
    int target_empty = 5;
    std::cout << "Empty array: " << sol.numSubseq(nums_empty, target_empty) << std::endl;

    return 0;
}
