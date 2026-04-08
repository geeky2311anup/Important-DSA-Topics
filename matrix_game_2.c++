#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast input/output (important for large test cases)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int n;
        cin >> n;  // Number of marked points on the circle

        vector<int> a(n);

        // Read the angles (positions on the circle)
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        // Sort angles to process them in circular order
        sort(a.begin(), a.end());

        // Store differences (arc lengths between consecutive points)
        vector<int> diffs;

        // Compute differences between adjacent sorted angles
        for (int i = 1; i < n; i++) {
            diffs.push_back(a[i] - a[i - 1]);
        }

        // Add the circular arc (last point to first point via 360° wrap)
        diffs.push_back(360 - a[n - 1] + a[0]);

        // Compute GCD of all arc lengths
        // This gives the largest equal division of the circle
        int g = diffs[0];
        for (int i = 1; i < n; i++) {
            g = gcd(g, diffs[i]);
        }

        // Total number of equal slices possible in the full circle
        int totalSlices = 360 / g;

        // We already have 'n' points (cuts), so remaining cuts needed:
        // total slices - existing cuts
        cout << (totalSlices - n) << "\n";
    }

    return 0; // Successful execution
}
