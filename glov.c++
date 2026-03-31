#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // Number of test cases

    while (T--) {

        int N;
        cin >> N;  // Number of fingers / glove slots

        vector<long long> handLens(N), gloveLens(N);

        // Input: lengths of fingers
        for (int i = 0; i < N; i++) cin >> handLens[i];

        // Input: lengths of glove slots
        for (int i = 0; i < N; i++) cin >> gloveLens[i];

        bool front = true, back = true;

        /*
            Check FRONT fit:
            We try to match finger i with glove slot i directly.
            Condition: finger length must be <= glove slot length
        */
        for (int i = 0; i < N; i++) {
            if (handLens[i] > gloveLens[i]) {
                front = false;  // If any mismatch, front fitting fails
                break;
            }
        }

        /*
            Check BACK fit:
            We try to match finger i with glove slot (N-1-i), i.e., reverse mapping.
            This simulates wearing glove in reverse orientation.
        */
        for (int i = 0; i < N; i++) {
            if (handLens[i] > gloveLens[N - 1 - i]) {
                back = false;  // If any mismatch, back fitting fails
                break;
            }
        }

        /*
            Final decision based on both checks:
            - both  : fits in both orientations
            - front : fits only in normal order
            - back  : fits only in reverse order
            - none  : doesn't fit in any way
        */
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
