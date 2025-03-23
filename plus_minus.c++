#include <bits/stdc++.h>
using namespace std;

#define ll long long

template<typename T, typename U> 
inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> 
inline void amax(T &x, U y) { if (x < y) x = y; }

ll readInt(ll l, ll r) {
    ll x = 0;
    bool is_neg = false;
    char g;
    while ((g = getchar()) < '0' || g > '9') {
        if (g == '-') is_neg = true;
    }
    x = g - '0';
    while ((g = getchar()) >= '0' && g <= '9') {
        x = x * 10 + (g - '0');
    }
    if (is_neg) x = -x;
    return x;
}

void solve() {
    int T = readInt(1, 1e5);
    int max_N = 0, min_N = 1e6, sum_N = 0;

    while (T--) {
        int N = readInt(2, 1e5);
        vector<vector<int>> groups(2);
        ll ans = 0;

        amin(min_N, N);
        amax(max_N, N);
        sum_N += N;

        for (int i = 1; i <= N; ++i) {
            int x = (i != N) ? readInt(-1e9, 1e9) : readInt(-1e9, 1e9);
            groups[i & 1].push_back(abs(x));
            ans += (i & 1) ? abs(x) : -abs(x);
        }

        sort(groups[0].begin(), groups[0].end());
        sort(groups[1].begin(), groups[1].end());

        ans = max(ans, ans + 2 * groups[0].back() - 2 * groups[1][0]);
        cout << ans << "\n";
    }

    cerr << T << " " << min_N << " " << max_N << " " << sum_N << "\n";
    assert(sum_N <= 2e5);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
