#include <bits/stdc++.h>

using namespace std;
#include <iostream>


#define endl "\n"
const int N = 1e3 + 5;

int t, n, a[N];
unordered_map < int, int > freq;

int32_t main() {
    cin >> t;
    while (t--) {
        freq.clear();
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        int max_freq = 0;
        int max_freq_count = 0;

        for (auto & i: freq) {
            if (i.second > max_freq) {
                max_freq = i.second;
                max_freq_count = 1;
            } else if (i.second == max_freq) {
                max_freq_count++;
            }
        }

        if (max_freq_count == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}