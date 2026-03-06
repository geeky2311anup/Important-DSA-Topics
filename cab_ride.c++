#include <bits/stdc++.h> // Includes all standard libraries (useful for CP)
using namespace std;

// Speeds up input and output operations by disabling synchronization with C stdio
inline void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run() {
    int n;
    cin >> n; // Read the input value for the current test case

    // Calculate initial answer: 100 * n. 
    // LL suffix ensures the calculation is done in long long to prevent overflow.
    long long ans = 100LL * n;

    // Special edge case: If n is 1, the answer is specifically set to 200.
    if (n == 1) {
        ans = 200;
    }

    cout << ans << '\n'; // Output the result followed by a newline
}

int main() {
    fast(); // Initialize fast I/O
    
    int t;
    cin >> t; // Read the number of test cases
    
    // Loop through each test case
    while (t--) {
        run();
    }
    
    return 0;
}
