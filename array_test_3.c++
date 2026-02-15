#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <iostream>


void solve() {
    int N, M;
    cin >> N >> M;
    long long max_distance = 0;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        max_distance += max(A - 1, M - A);
    }

    cout << max_distance << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
