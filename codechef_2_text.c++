#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Special case: if N is 0, print "0" and exit.
    if (N == 0) {
        cout << "0";
        return 0;
    }

    string binary = "";
    // Convert the number to binary by repeatedly dividing by 2
    while (N > 0) {
        int remainder = N % 2;
        // Prepend the remainder to the binary string
        binary = to_string(remainder) + binary;
        N /= 2;
    }

    cout << binary << "\n";
    return 0;
}
