#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxLength = 0;

        for (auto const& pair : freqMap) {
            int currentNum = pair.first;
            int currentNumFreq = pair.second;

            if (freqMap.count(currentNum + 1)) {
                int nextNumFreq = freqMap[currentNum + 1];
                maxLength = std::max(maxLength, currentNumFreq + nextNumFreq);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1 = {1, 3, 2, 2, 5, 2, 3, 7};
    std::cout << "Example 1: " << sol.findLHS(nums1) << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 4};
    std::cout << "Example 2: " << sol.findLHS(nums2) << std::endl;

    std::vector<int> nums3 = {1, 1, 1, 1};
    std::cout << "Example 3: " << sol.findLHS(nums3) << std::endl;

    std::vector<int> nums4 = {10, 11, 10, 12, 11, 11, 10};
    std::cout << "Custom Example 4: " << sol.findLHS(nums4) << std::endl;

    std::vector<int> nums5 = {1, 5, 10, 15};
    std::cout << "Custom Example 5: " << sol.findLHS(nums5) << std::endl;

    return 0;
}
