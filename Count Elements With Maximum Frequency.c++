class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Count how many times each number appears
        unordered_map<int, int> countMap;
        for (int value : nums) {
            countMap[value]++;
        }

        // Find the highest frequency
        int highestFreq = 0;
        for (auto [value, freq] : countMap) {
            highestFreq = max(highestFreq, freq);
        }

        // Count how many numbers have that highest frequency
        int numWithHighestFreq = 0;
        for (auto [value, freq] : countMap) {
            if (freq == highestFreq) {
                numWithHighestFreq++;
            }
        }

        // Each contributes its frequency count
        return numWithHighestFreq * highestFreq;
    }
};
