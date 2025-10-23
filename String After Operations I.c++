#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string &s) {
        int m = (int)s.size();
        int n = m - 2;

        int leftSum  = s[0] - '0';
        int rightSum = s[1] - '0';

        __int128 comb = 1; // will hold C(n, k) exactly
        for (int k = 1; k <= n; ++k) {
            comb = (comb * (n - (k - 1))) / k;      // C(n, k) from C(n, k-1)
            int c = (int)(comb % 10);               // only last digit matters
            leftSum  = (leftSum  + c * (s[k]   - '0')) % 10;
            rightSum = (rightSum + c * (s[k+1] - '0')) % 10;
        }
        return leftSum == rightSum;
    }
};
