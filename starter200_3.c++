#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    if (!(cin >> tc)) return 0;
    while (tc--) {
        int n;
        cin >> n;
        string out;
        out.reserve(n);
        for (int i = 0; i < n; ++i) {
            out.push_back(char('a' + (i % 5)));
        }
        cout << out << '\n';
    }
    return 0;
}
