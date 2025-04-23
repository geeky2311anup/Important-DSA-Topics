#include <iostream>
#include <vector>
#include <numeric> // Optional, for std::is_sorted

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> d[i];
        }

        bool isNonDecreasing = true;
        for (int i = 1; i < n; ++i) {
            if (d[i] < d[i - 1]) {
                isNonDecreasing = false;
                break;
            }
        }

        std::cout << (isNonDecreasing ? "Yes" : "No") << std::endl;
    }
    return 0;
}