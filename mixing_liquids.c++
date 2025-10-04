#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        int x, y;
        cin >> x >> y;
        int possible = min(x, y / 2);
        cout << (possible * 3) << "\n";
    }
    return 0;
}
