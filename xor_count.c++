#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n); // Pre-allocate the result vector for efficiency
        for (int i = 0; i < n; ++i) {
            result[i] = nums[nums[i]];
        }
        return result;
    }
};