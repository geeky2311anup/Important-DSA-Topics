#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countInterestingSubarrays(std::vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        std::unordered_map<int, int> prefixRemainderCount;
        long long interestingSubarrayCount = 0;
        int prefixSumMod = 0;
        prefixRemainderCount[0] = 1;
        

        for (int num : nums) {
            prefixSumMod = (prefixSumMod + (num % modulo == k)) % modulo;
            int targetRemainder = (prefixSumMod - k + modulo) % modulo;
            interestingSubarrayCount += prefixRemainderCount[targetRemainder];
            prefixRemainderCount[prefixSumMod]++;
            
        }
        return interestingSubarrayCount;
    }
};