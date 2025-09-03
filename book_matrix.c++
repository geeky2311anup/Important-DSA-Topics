#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = 0;

        for (int bit = 29; bit >= 0; bit--) {
            int abit = (a >> bit) & 1;
            int bbit = (b >> bit) & 1;
            int cbit = (c >> bit) & 1;

            int flip = 0;
            if (a > b && abit > bbit) flip = 1;
            if (b > c && bbit > cbit) flip = 1;
            if (a > c && abit > cbit) flip = 1;

            if (flip) {
                a ^= (1 << bit);
                b ^= (1 << bit);
                c ^= (1 << bit);
                x ^= (1 << bit);
            }
        }

        cout << (a < b && b < c ? x : -1) << "\n";
    }

    return 0;
}
