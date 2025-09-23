#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int n = nums.size();
        int leftBound = -1;
        int minKIndex = -1;
        int maxKIndex = -1;

        for (int right = 0; right < n; ++right) {
            if (nums[right] < minK || nums[right] > maxK) {
                leftBound = right;
                minKIndex = -1;
                maxKIndex = -1;
            }

            if (nums[right] == minK) {
                minKIndex = right;
            }

            if (nums[right] == maxK) {
                maxKIndex = right;
            }

            if (minKIndex > leftBound && maxKIndex > leftBound) {
                count += std::min(minKIndex, maxKIndex) - leftBound;
            }
        }


       
        return count;
    }
};