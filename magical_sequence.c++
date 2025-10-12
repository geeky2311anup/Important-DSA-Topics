#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;
    int comb[31][31]{};
    int N;

    void buildComb() {
        if (comb[0][0]) return;
        comb[0][0] = 1;
        for (int i = 1; i <= 30; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j)
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    long long modExp(long long base, int exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    unordered_map<long long, int> memo;

    int dfs(int left, int target, int idx, unsigned mask, vector<int>& vals) {
        int bits = __builtin_popcount(mask);
        if (left < 0 || target < 0 || left + bits < target) return 0;
        if (left == 0) return (target == bits);
        if (idx >= N) return 0;

        long long key = ((long long)left << 40) | ((long long)target << 32) | ((long long)idx << 24) | mask;
        if (auto it = memo.find(key); it != memo.end()) return it->second;

        long long ways = 0;
        for (int take = 0; take <= left; ++take) {
            long long choose = (1LL * comb[left][take] * modExp(vals[idx], take)) % MOD;
            unsigned newMask = mask + take;
            bool bitSet = newMask & 1;
            unsigned nextMask = newMask >> 1;
            ways = (ways + choose * dfs(left - take, target - bitSet, idx + 1, nextMask, vals)) % MOD;
        }
        return memo[key] = (int)ways;
    }

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        buildComb();
        N = nums.size();
        memo.clear();
        return dfs(m, k, 0, 0, nums);
    }
};
