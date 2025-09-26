#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int cntEven = 0;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) cntEven++;
        }

        int ans = -1;
        if (x % 2 == 1) {
            ans = (cntEven + 1) / 2;
        } else {
            if (cntEven < n) ans = cntEven;
        }

        cout << ans << "\n";
    }
    return 0;
}
