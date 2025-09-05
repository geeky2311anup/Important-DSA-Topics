#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long x;
        cin >> x;

        long long ans = x; // worst case: y very large, but x is a safe initial upper bound
        // iterate y from 1 until triangular number d >= x (we also check the step where d >= x)
        for (long long y = 1;; ++y) {
            long long d = y * (y + 1) / 2;          // triangular number
            long long cost = y + llabs(x - d);      // formula from original code
            ans = min(ans, cost);
            if (d >= x) break;                      // once d >= x, we can stop
        }

        cout << ans << '\n';
    }

    return 0;
}
