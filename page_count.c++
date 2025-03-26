#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sum /= (n - 1);

    for (int i = 0; i < n; ++i) {
        cout << (sum - a[i]) << (i == n - 1 ? '\n' : ' ');
    }
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
