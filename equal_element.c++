#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector < int > a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_map < int, int > freq;

        for (int x: a) {
            freq[x]++;
        }

        int maxFreq = 0;
        for (const auto & entry: freq) {
            if (entry.second > maxFreq) {
                maxFreq = entry.second;
            }
        }

        cout << n - maxFreq << endl;
    }

    return 0;
}
