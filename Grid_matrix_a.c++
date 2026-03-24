#include <bits/stdc++.h>
using namespace std;

int main() {

    // Enable fast input/output (important for competitive programming)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // Number of test cases

    // Process each test case
    while (T--) {

        int N;
        cin >> N;  // Size of the square matrix (N x N)

        // Loop through each row
        for (int row = 0; row < N; ++row) {

            // Loop through each column
            for (int col = 0; col < N; ++col) {

                /*
                 * Generate value using a cyclic pattern:
                 * (row + col + 1) % N produces values from 0 to N-1
                 * It "wraps around" when exceeding N-1
                 *
                 * Example (N = 4):
                 * Row 0 → 1 2 3 0
                 * Row 1 → 2 3 0 1
                 * Row 2 → 3 0 1 2
                 * Row 3 → 0 1 2 3
                 */
                int val = (row + col + 1) % N;

                // Print the current value
                cout << val;

                // Add space between elements (except after last column)
                if (col + 1 < N) 
                    cout << " ";
            }

            // Move to the next line after each row
            cout << "\n";
        }
    }

    return 0;  // Program ends successfully
}
