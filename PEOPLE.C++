#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1000000007;

        // Edge case: no days → no one knows the secret
        if (n == 0) return 0;

        // dp[i] → number of people who FIRST learn the secret on day i
        vector<int> dp(n + 1, 0);
        dp[1] = 1;  // On day 1, one person knows the secret

        // prefix[i] → cumulative sum of dp[1] to dp[i]
        // Helps us quickly calculate range sums
        vector<int> prefix(n + 1, 0);
        prefix[1] = 1;

        // Iterate through each day
        for (int day = 2; day <= n; ++day) {

            /*
             People who can share the secret on 'day' are those who:
             - learned it at least 'delay' days ago → j <= day - delay
             - have not forgotten it yet → j >= day - forget + 1

             So valid j lies in:
             [day - forget + 1, day - delay]
            */
            int left = day - forget + 1;
            int right = day - delay;

            // Only proceed if there exists a valid range
            if (right >= 1) {
                // Clamp left boundary to valid index
                if (left < 1) left = 1;

                // Use prefix sum to compute sum of dp[left...right]
                long long ways = prefix[right];

                if (left - 1 >= 1)
                    ways = (ways - prefix[left - 1] + MOD) % MOD;

                // These people will inform new people today
                dp[day] = (int)(ways % MOD);
            } else {
                // No one is eligible to share yet
                dp[day] = 0;
            }

            // Update prefix sum for future calculations
            prefix[day] = (prefix[day - 1] + dp[day]) % MOD;
        }

        /*
         Final answer:
         People who still REMEMBER the secret on day n are those who learned it
         in the last 'forget' days:

         Range: [n - forget + 1, n]
        */
        int start = max(1, n - forget + 1);

        long long result = prefix[n];
        if (start - 1 >= 1)
            result = (result - prefix[start - 1] + MOD) % MOD;

        return (int)result;
    }
};
