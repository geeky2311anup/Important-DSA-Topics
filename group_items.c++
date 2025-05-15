#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxLen = 1;
        int endIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) { // Changed loop direction for clarity
                if (groups[i] != groups[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }

        vector<string> result;
        int curr = endIndex;
        while (curr != -1) {
            result.push_back(words[curr]);
            curr = prev[curr];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
