#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        // Count frequency of each word
        map<string, int> counts;
        for (const string& word : words) {
            counts[word]++;
        }

        int total_length = 0;          // Stores final palindrome length
        bool has_center_word = false; // Tracks if we can place a middle word

        // Iterate through each unique word and its count
        for (auto const& [word, count] : counts) {
            
            // Create reversed version of the current word
            string reversed_word = word;
            reverse(reversed_word.begin(), reversed_word.end());

            // Case 1: Word is a palindrome itself (e.g., "aa", "bb")
            if (word == reversed_word) {
                
                // We can pair them (2 words = length 4)
                total_length += (count / 2) * 4;

                // If one is left, it can be placed in the center
                if (count % 2 == 1) {
                    has_center_word = true;
                }
            } 
            else {
                // Case 2: Word is not a palindrome (e.g., "ab" and "ba")
                
                // Check if reverse exists in map
                if (counts.count(reversed_word) && counts[reversed_word] > 0) {
                    
                    // Number of valid pairs we can form
                    int num_pairs = min(counts[word], counts[reversed_word]);
                    
                    // Each pair contributes 4 characters
                    total_length += num_pairs * 4;

                    // Mark both words as used to avoid double counting
                    counts[word] = 0;
                    counts[reversed_word] = 0;
                }
            }
        }

        // If we found a leftover palindrome word, place it in center
        if (has_center_word) {
            total_length += 2;
        }

        return total_length;
    }
};
