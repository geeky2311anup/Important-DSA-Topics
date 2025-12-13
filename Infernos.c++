#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, X;
        cin >> N >> X;
        vector<int> H(N);
        for (int i = 0; i < N; ++i) cin >> H[i];

        // Single-target mode: sum of ceil(H[i] / X)
        long long single_mode_time = 0;
        for (int h : H) {
            single_mode_time += (h + X - 1) / X; // integer ceil
        }

        // Multi-target mode: need max(H) seconds (1 damage to all living per second)
        int multi_mode_time = 0;
        for (int h : H) multi_mode_time = max(multi_mode_time, h);

        cout << min(single_mode_time, (long long)multi_mode_time) << '\n';
    }
    return 0;
}
