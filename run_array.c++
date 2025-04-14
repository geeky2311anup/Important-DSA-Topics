#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int x;
        std::cin >> x;
        if (x > 5000) {
            x -= 500;
        } else if (x > 1000) {
            x -= 100;
        } else if (x > 100) {
            x -= 25;
        }
        std::cout << x << std::endl;
    }
    return 0;
}