#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> frequency;
        for (auto ch : s) {
            frequency[ch]++;
        }

        int maxVowelFreq = 0, maxConsonantFreq = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (isVowel(ch)) {
                maxVowelFreq = max(maxVowelFreq, frequency[ch]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, frequency[ch]);
            }
        }
        return maxVowelFreq + maxConsonantFreq;
    }
};
