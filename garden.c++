#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        std::unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        int largestLucky = -1;
        for (auto const& pair : freq) {
            int value = pair.first;
            int frequency = pair.second;
            if (value == frequency) {
                largestLucky = std::max(largestLucky, value);
            }
        }
        return largestLucky;
    }
};