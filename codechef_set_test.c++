#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#include <cmath>


class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int n = str1.length(), m = str2.length();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
           
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            } 
    
            
            string result = "";
            int i = n, j = m;
            while (i > 0 || j > 0) {
                if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]) {
                    result = str1[i - 1] + result;
                    i--;
                    j--;
                } else if (i > 0 && (j == 0 || dp[i - 1][j] >= dp[i][j - 1])) {
                    result = str1[i - 1] + result;
                    i--;
                } else {
                    result = str2[j - 1] + result;
                    j--;
                }
            }
    
            return result;
        }
    };