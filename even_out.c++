#include <bits/stdc++.h>

using namespace std;

vector < int > good;

void init() {
    for (int i = 0; i <= 30; ++i) {
        for (int j = i + 1; j <= 30; ++j) {
            long long x = (1LL << i) + (1LL << j);
            if (x <= 2000000000) {
                good.push_back(x);
            }
        }
    }
}

int absi(int x) {
    return (x < 0 ? -x : x);
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = INT_MAX;
        for (int i = 0; i < good.size(); ++i) {
            ans = min(ans, absi(good[i] - n));
        }
        cout << ans << "\n";
    }
    return 0;
}
