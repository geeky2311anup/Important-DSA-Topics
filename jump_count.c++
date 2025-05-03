#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        // Check if it's possible to make all tops equal to x
        auto check = [&](int x) {
            int rotations = 0;
            for (int i = 0; i < n; ++i) {
                if (tops[i] != x && bottoms[i] != x) {
                    return INT_MAX; // Impossible to make tops all x
                } else if (tops[i] != x) {
                    rotations++;
                }
            }
            return rotations;
        };

        // Check if it's possible to make all bottoms equal to x
        auto checkBottoms = [&](int x) {
            int rotations = 0;
            for (int i = 0; i < n; ++i) {
                if (bottoms[i] != x && tops[i] != x) {
                    return INT_MAX; // Impossible to make bottoms all x
                } else if (bottoms[i] != x) {
                    rotations++;
                }
            }
            return rotations;
        };
        
        int ans = INT_MAX;
        // There are only 6 possible values (1 to 6) for the rows to be equal
        for (int i = 1; i <= 6; ++i) {
            
            ans = min(ans, check(i));
            ans = min(ans, checkBottoms(i));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

