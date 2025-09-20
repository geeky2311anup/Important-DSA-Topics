#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> ans(N);
        int y = N;

        // fill from the end toward the start, step 2
        int start = (N % 2 ? N - 1 : N - 2);
        for (int x = start; x >= 0; x -= 2) {
            ans[x] = y;
            if (x + 1 < N) ans[x + 1] = 2 * y;
            y--;
        }

        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
