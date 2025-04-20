#include <iostream>
#include <algorithm>

void solve() {
    int n, a;
    std::cin >> n >> a;
    std::cout << std::min(n - a, a) << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}