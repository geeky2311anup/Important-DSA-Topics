class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0;
        long long currentSum = 0;
        
        // 'left' marks the start of our sliding window
        int left = 0;

        // 'right' expands the window by iterating through each element
        for (int right = 0; right < n; ++right) {
            // Include the current element in the window sum
            currentSum += nums[right];

            /* The score of a subarray is defined as: sum * length.
               While the current window's score is >= k, it's invalid.
               We must shrink the window from the left to decrease the score.
            */
            while (left <= right && currentSum * (right - left + 1) >= k) {
                currentSum -= nums[left];
                left++;
            }

            /* After the while loop, all subarrays ending at 'right' and 
               starting between 'left' and 'right' are valid.
               The number of such subarrays is exactly the window length.
            */
            res += (right - left + 1);
        }
        
        return res;
    }
};
