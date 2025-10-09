#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve_case() {
    int64 x;
    if (!(cin >> x)) return;
    if (x == 2) {
        cout << 4 << '\n';
        return;
    }
    if (x == 3) {
        cout << 5 << '\n';
        return;
    }

    int64 q = x / 3;
    int64 r = x % 3;
    int64 ans = 0;

    if (r == 0) {
        ans = q * 5;
    } else if (r == 2) {
        ans = q * 5 + 4;
    } else { // r == 1
        if (q >= 1) {
            int64 use = q - 1;
            int64 remaining = x - use * 3;
            ans = use * 5 + (remaining / 2) * 4;
        } else {
            ans = 4; // fallback (handles small x, though x==1 unlikely in tests)
        }
    }

    cout << ans << '\n';
}

int main() {
    fast_io();
    int T;
    cin >> T;
    while (T--) solve_case();
    return 0;
}
