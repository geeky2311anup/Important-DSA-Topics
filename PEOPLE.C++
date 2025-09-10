#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1000000007;
        if (n == 0) return 0;

        // dp[i] = number of people who learn the secret on day i
        vector<int> dp(n + 1);
        dp[1] = 1;

        // prefix[i] = sum_{k=1..i} dp[k] (mod MOD)
        vector<int> prefix(n + 1);
        prefix[1] = 1;

        for (int day = 2; day <= n; ++day) {
            // people who can share on 'day' are those who learned on days j
            // such that j + delay <= day <= j + forget - 1
            // so j in [day - forget + 1, day - delay]
            int left = day - forget + 1;
            int right = day - delay;

            if (right >= 1) {
                if (left < 1) left = 1;
                long long sumRange = prefix[right];
                if (left - 1 >= 1) sumRange = (sumRange - prefix[left - 1] + MOD) % MOD;
                dp[day] = (int)(sumRange % MOD);
            } else {
                dp[day] = 0; // nobody is eligible to share yet
            }

            prefix[day] = (prefix[day - 1] + dp[day]) % MOD;
        }

        // result: people who still know the secret on day n are those who learned
        // on days in [n - forget + 1, n]
        int start = max(1, n - forget + 1);
        long long result = prefix[n];
        if (start - 1 >= 1) result = (result - prefix[start - 1] + MOD) % MOD;

        return (int)result;
    }
};
