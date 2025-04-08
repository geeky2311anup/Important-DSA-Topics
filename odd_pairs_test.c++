#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int odds = (n + 1) / 2;
        int evens = n / 2;
        long long result = 2LL * odds * evens;
        std::cout << result << std::endl;
    }
    return 0;
}