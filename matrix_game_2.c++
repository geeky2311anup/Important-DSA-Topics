#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        // find arc lengths
        vector<int> diffs;
        for (int i = 1; i < n; i++) {
            diffs.push_back(a[i] - a[i-1]);
        }
        diffs.push_back(360 - a[n-1] + a[0]);

        // gcd of all arc lengths
        int g = diffs[0];
        for (int i = 1; i < n; i++) {
            g = gcd(g, diffs[i]);
        }

        // total equal slices possible
        int totalSlices = 360 / g;

        // extra cuts needed
        cout << (totalSlices - n) << "\n";
    }
    return 0;
}
