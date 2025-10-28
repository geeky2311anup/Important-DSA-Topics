//problem link ->  https://www.codechef.com/problems/SULIM?tab=statement

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int highest = *max_element(b.begin(), b.end());
        int maxProfit = INT_MIN;

        for (int limit = 1; limit <= highest; ++limit) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (b[i] <= limit && a[i] > 0) {
                    sum += a[i];
                }
            }
            maxProfit = max(maxProfit, sum - limit);
        }

        cout << (maxProfit < 0 ? 0 : maxProfit) << '\n';
    }

    return 0;
}
