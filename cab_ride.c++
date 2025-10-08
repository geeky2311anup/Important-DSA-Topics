#include <bits/stdc++.h>
using namespace std;

inline void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run() {
    int n;
    cin >> n;
    long long ans = 100LL * n;
    if (n == 1) ans = 200;
    cout << ans << '\n';
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) run();
    return 0;
}
