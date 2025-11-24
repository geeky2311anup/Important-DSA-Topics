#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <iostream>


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << min(k, n - k) << "\n";
    }
    return 0;
}
