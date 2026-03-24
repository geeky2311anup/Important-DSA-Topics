```cpp
#include <bits/stdc++.h>
using namespace std;

#define _z ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;

    // Compute result = n / gcd(n, k)
    int result = n / __gcd(n, k);

    cout << result << endl;
}

int main() {
    _z;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
```
