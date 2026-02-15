#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> nextNums;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) nextNums.push_back(nums[k]);
                }

                for (double val : compute(nums[i], nums[j])) {
                    nextNums.push_back(val);
                    if (solve(nextNums)) return true;
                    nextNums.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b) {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (fabs(b) > 1e-6) results.push_back(a / b);
        if (fabs(a) > 1e-6) results.push_back(b / a);
        return results;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> cards = {4, 1, 8, 7};
    
    bool result = sol.judgePoint24(cards);
    cout << "Can form 24 with cards [4, 1, 8, 7]: " << (result ? "Yes" : "No") << endl;
    
    return 0;
}
