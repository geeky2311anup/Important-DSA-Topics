#include <iostream>
#include <vector>
#include <algorithm> // For std::sort, if needed for other parts of the solution

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> distinct;
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != A[i - 1]) {
            distinct.push_back(A[i]);
        }
    }
    cout << distinct.size() << "\n";
    for (int num : distinct) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}