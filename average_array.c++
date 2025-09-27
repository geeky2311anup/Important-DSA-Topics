#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        if (n & 1) {
            cout << x << ' ';
            for (long long i = 1; i <= n / 2; ++i)
                cout << x - i << ' ' << x + i << ' ';
        } else {
            for (long long i = 1; i <= n / 2; ++i)
                cout << x - i << ' ' << x + i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
