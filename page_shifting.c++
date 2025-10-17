#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<long long, int> cache;

    int helper(int idx, string& str, int mask, bool changeAllowed, int k) {
        if (idx == (int)str.size()) return 0;

        long long state = ((long long)idx << 27) | ((long long)mask << 1) | (changeAllowed ? 1LL : 0LL);
        if (cache.find(state) != cache.end()) return cache[state];

        int bit = 1 << (str[idx] - 'a');
        int merged = mask | bit;
        int best;

        if (__builtin_popcount(merged) > k)
            best = 1 + helper(idx + 1, str, bit, changeAllowed, k);
        else
            best = helper(idx + 1, str, merged, changeAllowed, k);

        if (changeAllowed) {
            for (int c = 0; c < 26; ++c) {
                int nextBit = 1 << c;
                int nextMask = mask | nextBit;
                int res;
                if (__builtin_popcount(nextMask) > k)
                    res = 1 + helper(idx + 1, str, nextBit, false, k);
                else
                    res = helper(idx + 1, str, nextMask, false, k);
                best = max(best, res);
            }
        }

        return cache[state] = best;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return 1 + helper(0, s, 0, true, k);
    }
};
