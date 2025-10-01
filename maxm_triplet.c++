#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll x, y;
    cin >> x >> y;

    ll score = 0;

    // use as many (2 from x + 1 from y) triples as possible
    ll take = min(x / 2, y);
    score += take * 2;
    x -= take * 2;
    y -= take;

    // if still some y left, use (1 from x + 2 from y) or (3 from y)
    take = min(x, y / 2);
    score += take * 2;
    x -= take;
    y -= take * 2;

    // use remaining pure x triples
    score += (x / 3);

    // use remaining pure y triples
    score += (y / 3) * 2;

    cout << score << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
