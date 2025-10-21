#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < N; ++col) {
                int val = (row + col + 1) % N;
                cout << val;
                if (col + 1 < N) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
