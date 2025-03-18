#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, bitwiseAnd = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); right++) {
            // Ensure the AND property holds
            while ((bitwiseAnd & nums[right]) != 0) {
                bitwiseAnd ^= nums[left];  // Remove nums[left] from bitmask
                left++;
            }
            // Include nums[right] in the window
            bitwiseAnd |= nums[right];

            // Update maximum length found
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
