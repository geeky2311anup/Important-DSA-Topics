#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcases;
    cin >> tcases;
    while (tcases--) {
        int len;
        cin >> len;
        string s;
        cin >> s;

        // mark positions that are covered by any "111" group
        vector<bool> covered(len, false);

        // scan for consecutive triplets and mark them
        for (int i = 0; i + 2 < len; ++i) {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1') {
                covered[i] = covered[i + 1] = covered[i + 2] = true;
            }
        }

        // verify every '1' is part of some marked triplet
        bool valid = true;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '1' && !covered[i]) {
                valid = false;
                break;
            }
        }

        cout << (valid ? "Yes" : "No") << '\n';
    }

    return 0;
}
