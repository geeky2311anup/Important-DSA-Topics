class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();          // Get the size of the input array
        vector<int> ans;              // This will store the duplicate (sneaky) numbers
        vector<int> v(n, -1);         // Helper array initialized with -1 to track seen numbers

        for (int i = 0; i < n; i++) {
            // If the number has not been seen before
            if (v[nums[i]] == -1) {
                v[nums[i]] = nums[i]; // Mark the number as seen
            }
            else {
                // If already seen, it is a duplicate
                ans.push_back(nums[i]);
            }
        }
        return ans; // Return the list of sneaky (duplicate) numbers
    }
};
