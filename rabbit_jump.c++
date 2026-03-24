#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {

        // Length of the domino string
        int N = dominoes.size();

        // Stores positions of non-dot dominoes
        vector<int> indexes;

        // Stores the corresponding symbols (L or R)
        vector<char> symbols;

        // Add a virtual domino at position -1 with 'L'
        // This helps handle the left boundary easily
        indexes.push_back(-1);
        symbols.push_back('L');

        // Collect indexes and symbols of all non '.' dominoes
        for (int i = 0; i < N; ++i) {
            if (dominoes[i] != '.') {
                indexes.push_back(i);
                symbols.push_back(dominoes[i]);
            }
        }

        // Add a virtual domino at position N with 'R'
        // This helps handle the right boundary easily
        indexes.push_back(N);
        symbols.push_back('R');

        // Copy the original string to modify the result
        string ans = dominoes;

        // Process every pair of consecutive dominoes
        for (int index = 0; index < indexes.size() - 1; ++index) {

            int i = indexes[index];       // current domino index
            int j = indexes[index + 1];   // next domino index

            char x = symbols[index];      // current domino direction
            char y = symbols[index + 1];  // next domino direction

            // Case 1: Same direction (L...L or R...R)
            // All dominoes in between fall in the same direction
            if (x == y) {
                for (int k = i + 1; k < j; ++k) {
                    ans[k] = x;
                }
            }

            // Case 2: R...L situation
            // Dominoes fall towards each other
            else if (x > y) { // 'R' > 'L'
                for (int k = i + 1; k < j; ++k) {

                    // If equal distance from both sides → remains '.'
                    if (k - i == j - k)
                        ans[k] = '.';

                    // Closer to R side
                    else if (k - i < j - k)
                        ans[k] = 'R';

                    // Closer to L side
                    else
                        ans[k] = 'L';
                }
            }

            // Case 3: L...R situation
            // Dominoes stay unchanged (remain '.')
        }

        return ans;
    }
};
