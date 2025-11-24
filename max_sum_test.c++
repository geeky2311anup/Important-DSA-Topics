#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(std::vector<int>& nums) {
        std::map<int, std::vector<int>> sums;
        for (int num : nums) {
            int sum = digitSum(num);
            sums[sum].push_back(num);
        }

        int maxSum = -1;
        for (auto& [sum, numbers] : sums) { 
            if (numbers.size() >= 2) {
                std::sort(numbers.begin(), numbers.end());
                maxSum = std::max(maxSum, numbers[numbers.size() - 1] + numbers[numbers.size() - 2]);
            }
        }
        return maxSum;
    }
};