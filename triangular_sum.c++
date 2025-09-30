#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int len = nums.size(); len > 1; --len) {
            for (int i = 0; i < len - 1; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums.empty() ? 0 : nums[0];
    }
};
