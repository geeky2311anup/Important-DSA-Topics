#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int odds = 0;
        for (auto &p : freq) {
            if (p.second % 2 != 0) {
                odds++;
            }
        }

        if (n % 2 == 0) {
            if (odds == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        } else {
            if (freq.size() == 1)
                cout << 2 << "\n";
            else if (odds == 1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }

    return 0;
}
