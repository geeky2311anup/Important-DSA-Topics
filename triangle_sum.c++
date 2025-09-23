#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>


static const int MAXN = 1'000'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Count distinct prime factors (omega) for all numbers up to MAXN
    vector<int> omega(MAXN + 1, 0);
    for (int p = 2; p <= MAXN; ++p) {
        if (omega[p] == 0) {                // p is prime
            for (int multiple = p; multiple <= MAXN; multiple += p) {
                ++omega[multiple];          // count prime p once for each multiple
            }
        }
    }

    // 2) Prefix sum of omega to query sums quickly
    // pref[i] = sum_{k=1..i} omega(k)
    vector<long long> pref(MAXN + 1, 0);
    for (int i = 1; i <= MAXN; ++i) pref[i] = pref[i - 1] + omega[i];

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n > m) swap(n, m);

        // Energy from n to m is sum over k = n..m-1 of omega(k)
        // Handle n == m (no move → 0 energy) gracefully.
        long long ans = (n <= m - 1) ? (pref[m - 1] - pref[n - 1]) : 0;
        
        cout << ans << '\n';
    }
    return 0;
}
