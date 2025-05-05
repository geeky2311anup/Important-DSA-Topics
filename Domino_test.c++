#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if (n <= 2) {
            return n;
        }
        
        long long MOD = 1e9 + 7;
        vector<long long> full(n + 1); // full[i]: # of ways to tile 2 x i
        vector<long long> partial(n + 1); // partial[i]: # of ways to tile 2 x i with one corner missing

        full[0] = 1;
        full[1] = 1;
        full[2] = 2;
        partial[1] = 1;
        partial[2] = 2;

        for (int i = 3; i <= n; ++i) {
            full[i] = (full[i - 1] + full[i - 2] + 2 * partial[i - 2]) % MOD;
            partial[i] = (partial[i - 1] + full[i - 1]) % MOD;
        }

        return (int)full[n];
    }
};
