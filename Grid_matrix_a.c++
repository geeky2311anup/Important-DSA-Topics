#include <bits/stdc++.h>
using namespace std;

int main() {

    // Fast input/output for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // Number of test cases

    // Loop through each test case
    while (T--) {

        int N;
        cin >> N;  // Size of the square matrix (N x N)

        // Iterate through each row
        for (int row = 0; row < N; ++row) {

            // Iterate through each column
            for (int col = 0; col < N; ++col) {

                // Compute value using cyclic pattern
                // (row + col + 1) % N ensures values wrap around from 0 to N-1
                int val = (row + col + 1) % N;

                // Print the value
                cout << val;

                // Print space between elements except after the last column
                if (col + 1 < N) 
                    cout << " ";
            }

            // Move to the next line after finishing a row
            cout << "\n";
        }
    }

    return 0;  // End of program
}
