#include <bits/stdc++.h>
using namespace std;

int main() {

    // Fast I/O for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;   // Number of test cases

    // Process each test case
    while (t--) {

        int n;
        cin >> n;   // Dimension of the square matrix (n x n)

        // Traverse rows
        for (int i = 0; i < n; ++i) {

            // Traverse columns
            for (int j = 0; j < n; ++j) {

                /*
                 * Value generation logic:
                 * We use (i + j + 1) % n to create a cyclic pattern.
                 *
                 * Key idea:
                 * - Values always remain in range [0, n-1]
                 * - Each row is a shifted version of the previous row
                 * - Ensures a structured repeating pattern
                 *
                 * Example (n = 4):
                 * 1 2 3 0
                 * 2 3 0 1
                 * 3 0 1 2
                 * 0 1 2 3
                 */
                int value = (i + j + 1) % n;

                // Output current element
                cout << value;

                // Print space except after last column
                if (j != n - 1) {
                    cout << " ";
                }
            }

            // Move to next row
            cout << '\n';
        }
    }

    return 0;  // Successful execution
}
