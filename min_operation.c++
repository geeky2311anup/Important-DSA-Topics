#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        int n = nums.size();
        for (int k = 0; k * 3 <= n; ++k) {
            std::unordered_set<int> seen;
            bool unique = true;
            for (int i = k * 3; i < n; ++i) {
                
                if (seen.count(nums[i])) {
                    unique = false;

                    break;
                }
                seen.insert(nums[i]);
            }
            if (unique) {
                return k;
            }
        }
        return (n + 2) / 3; // Equivalent to ceil(n / 3.0)
    }
};