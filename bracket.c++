#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> counts;
        for (const string& word : words) {
            counts[word]++;
        }

        int total_length = 0;
        bool has_center_word = false;

        for (auto const& [word, count] : counts) {
            string reversed_word = word;
            reverse(reversed_word.begin(), reversed_word.end());

            if (word == reversed_word) {
                total_length += (count / 2) * 4;
                if (count % 2 == 1) {
                    has_center_word = true;
                }
            } else {
                if (counts.count(reversed_word) && counts[reversed_word] > 0) {
                    int num_pairs = min(counts[word], counts[reversed_word]);
                    total_length += num_pairs * 4;
                    counts[word] = 0;
                    counts[reversed_word] = 0;
                }
            }
        }

        if (has_center_word) {
            total_length += 2;
        }

        return total_length;
    }
};
