#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        for (int num : nums) {
            if (num == 0) {
                count++;
                ans += count; // add ongoing streak length
            } else {
                count = 0;
            }
        }
        return ans;
    }
};
