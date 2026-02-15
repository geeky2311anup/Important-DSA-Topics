#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> dp;

    int dfs(int curIndex, int count, const std::vector<std::vector<int>>& events) {
        if (count == 0 || curIndex == events.size()) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }

        int skip_current_event = dfs(curIndex + 1, count, events);

        int nextIndex = bisectRight(events, events[curIndex][1]);
        int attend_current_event = events[curIndex][2] + dfs(nextIndex, count - 1, events);

        return dp[count][curIndex] = std::max(skip_current_event, attend_current_event);
    }

    int bisectRight(const std::vector<std::vector<int>>& events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int maxValue(std::vector<std::vector<int>>& events, int k) {
        std::sort(events.begin(), events.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        int n = events.size();
        dp.assign(k + 1, std::vector<int>(n, -1));
        
        return dfs(0, k, events);
    }
};

int main() {
    Solution sol;

    std::vector<std::vector<int>> events1 = {{1,2,4},{3,4,3},{2,3,1}};
    int k1 = 2;
    std::cout << "Example 1: " << sol.maxValue(events1, k1) << std::endl;

    std::vector<std::vector<int>> events2 = {{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
    int k2 = 3;
    std::cout << "Example 2: " << sol.maxValue(events2, k2) << std::endl;

    std::vector<std::vector<int>> events3 = {{1,2,4},{3,4,3},{2,3,1}};
    int k3 = 3;
    std::cout << "Example 3: " << sol.maxValue(events3, k3) << std::endl;

    std::vector<std::vector<int>> events4 = {{1,5,10},{6,10,20},{11,15,5}};
    int k4 = 1;
    std::cout << "Example 4: " << sol.maxValue(events4, k4) << std::endl;

    std::vector<std::vector<int>> events5 = {{1,5,10},{6,10,20},{11,15,5}};
    int k5 = 2;
    std::cout << "Example 5: " << sol.maxValue(events5, k5) << std::endl;

    return 0;
}
