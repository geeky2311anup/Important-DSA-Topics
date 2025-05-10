#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zeros1 = 0, zeros2 = 0;

        for (int val : nums1) {
            if (val == 0) {
                zeros1++;
            }
            sum1 += val;
        }

        for (int val : nums2) {
            if (val == 0) {
                zeros2++;
            }
            sum2 += val;
        }

        if ((zeros1 == 0 && sum2 + zeros2 > sum1) || (zeros2 == 0 && sum1 + zeros1 > sum2)) {
            return -1;
        }

        return max(sum1 + zeros1, sum2 + zeros2);
    }
};
