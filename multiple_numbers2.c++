#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast input/output for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // Number of test cases

    // Loop through each test case
    while (t--) {
        int n, x;
        cin >> n >> x;  // n = number of elements, x = target value

        int cntEven = 0;   // Counter to store number of even elements
        vector<int> a(n);  // Array to store elements

        // Input array elements and count even numbers
        for (int i = 0; i < n; i++) {
            cin >> a[i];

            // Check if current element is even
            if (a[i] % 2 == 0)
                cntEven++;
        }

        int ans = -1;  // Default answer if condition cannot be satisfied

        // Case 1: If x is odd
        if (x % 2 == 1) {
            // Minimum operations needed based on even elements
            ans = (cntEven + 1) / 2;
        } 
        // Case 2: If x is even
        else {
            // If there is at least one odd element
            if (cntEven < n)
                ans = cntEven;
        }

        // Output the result for the current test case
        cout << ans << "\n";
    }

    return 0;  // End of program
}
