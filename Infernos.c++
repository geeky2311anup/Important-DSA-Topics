#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimizes standard I/O operations for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    // Read the number of test cases
    if (!(cin >> T)) return 0;
    
    while (T--) {
        int N, X;
        // N: number of targets, X: damage per second in single-target mode
        cin >> N >> X;
        
        vector<int> H(N);
        for (int i = 0; i < N; ++i) {
            cin >> H[i];
        }

        // Strategy 1: Single-target mode
        // Total time = sum of seconds needed to kill each target individually.
        // We use ceiling division: ceil(h / X)
        long long single_mode_time = 0;
        for (int h : H) {
            // (h + X - 1) / X is a standard trick for integer ceiling division
            single_mode_time += (long long)(h + X - 1) / X; 
        }

        // Strategy 2: Multi-target mode (AoE)
        // Since every target takes 1 damage per second, the total time 
        // is determined by the target with the highest health.
        int multi_mode_time = 0;
        for (int h : H) {
            multi_mode_time = max(multi_mode_time, h);
        }

        // The answer is the most efficient of the two strategies
        cout << min(single_mode_time, (long long)multi_mode_time) << '\n';
    }
    return 0;
}
