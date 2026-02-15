#include <bits/stdc++.h>
using namespace std;
#include <iostream>


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long L, R;
        cin >> L >> R;

        // Count multiples of 3 in [L, R]
        long long count = R / 3 - (L - 1) / 3;
        cout << count << "\n";
    }

    return 0;
}
