#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<vector<int>> S(N, vector<int>(N));
    vector<vector<int>> dp(N, vector<int>(N, -1e9));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    dp[N-1][N-1] = 0;

    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (i == N - 1 && j == N - 1) continue;
            
            int right = (j + 1 < N) ? dp[i][j + 1] : -1e9;
            int down = (i + 1 < N) ? dp[i + 1][j] : -1e9;
            
            dp[i][j] = S[i][j] + std::max(right, down);
        }
    }

    int maxSum = dp[0][0];
    int numJudges = (2 * N - 3);
    double maxAverage = (double)maxSum / numJudges;

    if (maxAverage < 0) {
        cout << "Bad Judges" << endl;
    } else {
        cout << fixed << setprecision(6) << maxAverage << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
