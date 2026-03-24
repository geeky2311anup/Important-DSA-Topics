```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void processCase() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<ll, int> lastPos;
    lastPos.reserve(n * 2);

    vector<int> nextIndex(n, -1);

    ll suffixXor = 0;
    lastPos[0] = n;

    for (int i = n - 1; i >= 0; i--) {
        suffixXor ^= a[i];

        if (lastPos.count(suffixXor)) {
            nextIndex[i] = lastPos[suffixXor] - 1;
        }

        lastPos[suffixXor] = i;
    }

    vector<ll> best(n, 0);
    ll answer = 0;

    for (int i = n - 1; i >= 0; i--) {
        best[i] = a[i];

        if (nextIndex[i] != -1) {
            best[i] += best[nextIndex[i]];
        }

        answer = max(answer, best[i]);
    }

    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        processCase();
    }

    return 0;
}
```
