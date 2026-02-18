#include <vector>
#include <algorithm>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        // Edge case: if array is empty or k is invalid
        if (nums.empty() || k <= 0) {
            return 0;
        }

        // Find the maximum element in the array
        int maxElement = *std::max_element(nums.begin(), nums.end());

        long long ans = 0;

        // Sliding window pointers
        int start = 0;

        // Count of max elements in the current window
        int maxElementsInWindow = 0;

        // Expand the window using 'end'
        for (int end = 0; end < nums.size(); ++end) {

            // If current element is the max element,
            // increase its count in the window
            if (nums[end] == maxElement) {
                maxElementsInWindow++;
            }

            // If window contains exactly k max elements,
            // shrink from the left
            while (maxElementsInWindow == k) {

                // If removing start affects max count,
                // update the counter
                if (nums[start] == maxElement) {
                    maxElementsInWindow--;
                }

                start++;
            }

            // All subarrays ending at 'end'
            // and starting before 'start' are valid
            ans += start;
        }

        // Return total valid subarrays
        return ans;
    }
};
