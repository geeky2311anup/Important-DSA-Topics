#include <vector>

using namespace std;

class Solution {
public:
    bool canZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> delta(n + 1, 0); // Difference array

        // Apply first k queries using the difference array
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            delta[l] -= val;
            delta[r + 1] += val; // Restore after r
        }

        // Apply the difference array to nums
        int currentDecrement = 0;
        for (int i = 0; i < n; i++) {
            currentDecrement += delta[i];
            if (nums[i] + currentDecrement > 0)
                return false; // If any element is still > 0, we fail
        }

        return true; // nums becomes a zero array
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // ✅ Fix: If nums is already a Zero Array, return 0
        bool alreadyZero = true;
        for (int num : nums) {
            if (num > 0) {
                alreadyZero = false;
                break;
            }
        }
        if (alreadyZero) return 0; // If nums is already zero, no need to process queries

        int left = 1, right = queries.size(), result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canZeroArray(nums, queries, mid)) {
                result = mid; // Found a valid `k`, try for a smaller `k`
                right = mid - 1;
            } else {
                left = mid + 1; // Increase `k`
            }
        }

        return result;
    }
};
