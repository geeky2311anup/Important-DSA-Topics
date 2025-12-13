#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                    vector<int>& groups) {
            int n = words.size();
            vector<int> dp(n, 1);       // Length of longest subsequence ending at i
            vector<int> parent(n, -1);  // To reconstruct the sequence
            int maxLengthIndex = 0;
    
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (isOneCharDiff(words[j], words[i]) && groups[i] != groups[j] && dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
                if (dp[i] > dp[maxLengthIndex]) {
                    maxLengthIndex = i;
                }
            }
    
            // Reconstruct the longest valid subsequence
            vector<string> result;
            for (int i = maxLengthIndex; i != -1; i = parent[i]) {
                result.push_back(words[i]);
            }
            reverse(result.begin(), result.end());
            return result;
        }
    
    private:
        // Check if exactly one character differs between s1 and s2
        bool isOneCharDiff(const string& s1, const string& s2) {
            if (s1.size() != s2.size()) return false;
    
            int diffCount = 0;
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] != s2[i]) {
                    ++diffCount;
                    if (diffCount > 1) return false;
                }
            }
            return diffCount == 1;
        }
    };
    