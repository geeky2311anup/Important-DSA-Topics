#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases > 0) {

        int total, choose;
        cin >> total >> choose;

        // We want the minimum between k and (n - k)
        int answer = (choose < total - choose) ? choose : (total - choose);

        cout << answer << '\n';

        testCases--;
    }

    return 0;
}
