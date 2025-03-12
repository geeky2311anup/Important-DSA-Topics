#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int posCount = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(negCount, posCount);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {-2, -1, -1, 1, 2, 3};
    vector<int> nums2 = {-3, -2, -1, 0, 0, 1, 2};
    vector<int> nums3 = {5, 20, 66, 1314};
    
    cout << sol.maximumCount(nums1) << endl; // Output: 3
    cout << sol.maximumCount(nums2) << endl; // Output: 3
    cout << sol.maximumCount(nums3) << endl; // Output: 4
    
    return 0;
}
