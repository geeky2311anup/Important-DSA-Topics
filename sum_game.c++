#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
        int minPrefixSum = 0;
        int maxPrefixSum = 0;
        int currentPrefixSum = 0;

        for (int diff : differences) {
            currentPrefixSum += diff;
            minPrefixSum = std::min(minPrefixSum, currentPrefixSum);
            maxPrefixSum = std::max(maxPrefixSum, currentPrefixSum);

            if (maxPrefixSum - minPrefixSum > upper - lower) {
                return 0;
            }
        }

        return (upper - lower) - (maxPrefixSum - minPrefixSum) + 1;
    }
};