#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // handle empty input
        if (words.empty()) return {};

        // build a vector of sorted forms (normalized representation)
        vector<string> sortedForms;
        sortedForms.reserve(words.size());
        for (const string &w : words) {
            string tmp = w;
            sort(tmp.begin(), tmp.end());
            sortedForms.push_back(move(tmp));
        }

        // collect results keeping only the first word of each anagram-group
        vector<string> answer;
        answer.reserve(words.size());
        answer.push_back(words[0]);

        for (size_t i = 1; i < words.size(); ++i) {
            // compare normalized forms of current and previous words
            if (sortedForms[i] != sortedForms[i - 1]) {
                answer.push_back(words[i]);
            }
        }

        return answer;
    }
};
