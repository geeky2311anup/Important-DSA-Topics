#include <iostream>

using namespace std;

// Function to solve one test case
void solve() {
    int n, x;
    cin >> n >> x;  // Read integers n and x

    // Check if x is divisible by n
    if (x % n == 0) {
        cout << "YES" << endl;  // If divisible, print YES
    } else {
        cout << "NO" << endl;   // Otherwise, print NO
    }
}

int main() {
    int t;
    cin >> t;  // Read number of test cases

    // Process each test case
    while (t--) {
        solve();
    }

    return 0;  // Indicate successful program termination
}
