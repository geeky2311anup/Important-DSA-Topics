class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < nums.size(); i++) {
            if (indexMap.find(target - nums[i]) != indexMap.end()) {
                return {indexMap[target - nums[i]], i};
            }
            indexMap[nums[i]] = i;
        }
        return {}; 
    }
};
