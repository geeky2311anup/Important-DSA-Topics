class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> unique;
        long long sumUnique = 0, sumAll = 0;

        for (int num : nums) {
            if (unique.find(num) == unique.end()) {
                unique.insert(num);
                sumUnique += num;   // add only once
            }
            sumAll += num;  // add every occurrence
        }

        return (int)(2 * sumUnique - sumAll);
    }
};
