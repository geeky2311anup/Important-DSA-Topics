#include <bits/stdc++.h>
using namespace std;

// Function to solve one test case
void solve() {
    int grps_w = 0, grps_b = 0;  // Counters for white and black groups

    int n;
    string s;

    cin >> n >> s;  // Read length and string

    // Traverse the string to count consecutive groups
    for (int i = 0; i < n; i++) {

        // Ensure input only contains 'B' or 'W'
        assert(s[i] == 'B' || s[i] == 'W');

        int j = i + 1;

        // If current character is 'W'
        if (s[i] == 'W') {
            grps_w++;  // New white group found

            // Skip all consecutive 'W'
            while (j < n && s[j] == s[i]) {
                j++;
            }
        } 
        else {  // Current character is 'B'
            grps_b++;  // New black group found

            // Skip all consecutive 'B'
            while (j < n && s[j] == s[i]) {
                j++;
            }
        }

        // Move i to the end of the current group
        i = j - 1;
    }

    // Output the minimum number of groups between black and white
    cout << min(grps_b, grps_w) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // For local testing (disabled on online judge)
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tests;
    cin >> tests;  // Number of test cases

    // Process each test case
    while (tests--) {
        solve();
    }
}
