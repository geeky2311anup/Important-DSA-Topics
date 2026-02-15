#include <vector>
using namespace std;


class Solution {
public:
    int countPairs(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        int pairCount = 0; // Number of pairs meeting the requirements
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((static_cast<long long>(i) * j) % k == 0 && nums[i] == nums[j]) {
                    pairCount++;
                }
            }
        }
        return pairCount;
        
    }
};