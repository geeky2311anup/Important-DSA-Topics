#include <iostream>
#include <vector>
#include <numeric> // Potentially useful for sum, but not strictly needed for this solution

using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                ans -= i;
            } else {
                ans += i;
            }
        }
        return ans;
    }
};