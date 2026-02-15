#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>


class Solution {
public:
    void solve() {
        int N;
        cin >> N;
        vector<int> B(N);
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }

        int ones = count(B.begin(), B.end(), 1);
        if (ones % 2 == 0) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        sol.solve();
    }

    return 0;
}
