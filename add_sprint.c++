class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n = nums.size();            // total number of elements in the array
        long long res = 0;              // stores the final count of valid subarrays
        long long currentSum = 0;       // sum of elements inside the current window
        
        // left pointer represents the start of the sliding window
        int left = 0;

        // right pointer expands the window one element at a time
        for (int right = 0; right < n; ++right) {

            // include nums[right] into the current window
            currentSum += nums[right];

            /*
            Score of a subarray = (sum of elements) * (length of subarray)

            If the score becomes >= k, the current window is invalid.
            To make it valid again, shrink the window from the left side
            by removing elements and moving the left pointer forward.
            */
            while (left <= right && currentSum * (right - left + 1) >= k) {

                // remove the leftmost element from the window
                currentSum -= nums[left];

                // move the window start forward
                left++;
            }

            /*
            After the above loop, the window [left ... right] becomes valid.

            All subarrays ending at 'right' and starting from any index
            between 'left' and 'right' will also be valid.

            Number of such subarrays = window length
                                    = (right - left + 1)
            */
            res += (right - left + 1);
        }

        // return the total count of valid subarrays
        return res;
    }
};
