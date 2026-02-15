#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Phase 1: Frequency Mapping
        // We use an unordered_map to store the count of each unique number.
        // Key: the number from the array, Value: how many times it appears.
        unordered_map<int, int> countMap;
        for (int value : nums) {
            countMap[value]++;
        }

        // Phase 2: Identifying the Peak Frequency
        // We iterate through the map to find the largest frequency value present.
        int highestFreq = 0;
        for (auto const& [value, freq] : countMap) {
            highestFreq = max(highestFreq, freq);
        }

        // Phase 3: Summing the Total Occurrences
        // We count how many distinct numbers reached that 'highestFreq'.
        int numWithHighestFreq = 0;
        for (auto const& [value, freq] : countMap) {
            if (freq == highestFreq) {
                numWithHighestFreq++;
            }
        }

        // Final Calculation:
        // Total count = (Number of elements with max frequency) * (The max frequency value)
        return numWithHighestFreq * highestFreq;
    }
};
