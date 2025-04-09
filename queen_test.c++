#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        long long ans = 2LL * n; // row + column
        ans += n - std::abs(x - y); // diagonal 1
        ans += n - std::abs(n + 1 - (x + y)); // diagonal 2
        std::cout << ans - 4 << std::endl;
    }
    return 0;
}