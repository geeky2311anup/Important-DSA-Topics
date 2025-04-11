#include <iostream>

int main() {
    int number;
    std::cin >> number;

    // Setting the first bit (0-indexed from the right) to 1
    number = number | (1 << 0);

    // Setting the second bit (1-indexed from the right) to 0
    number = number & ~(1 << 1);

    // Toggling the third bit (2-indexed from the right)
    number = number ^ (1 << 2);

    std::cout << number << std::endl;
    return 0;
}