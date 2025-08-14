#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> handLens(N), gloveLens(N);

        for (int i = 0; i < N; i++) cin >> handLens[i];
        for (int i = 0; i < N; i++) cin >> gloveLens[i];

        bool front = true, back = true;

        // Check front fit
        for (int i = 0; i < N; i++) {
            if (handLens[i] > gloveLens[i]) {
                front = false;
                break;
            }
        }

        // Check back fit
        for (int i = 0; i < N; i++) {
            if (handLens[i] > gloveLens[N - 1 - i]) {
                back = false;
                break;
            }
        }

        if (front && back) {
            cout << "both\n";
        } else if (front) {
            cout << "front\n";
        } else if (back) {
            cout << "back\n";
        } else {
            cout << "none\n";
        }
    }
    return 0;
}
