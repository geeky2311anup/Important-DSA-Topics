#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Fast input/output
    cin.tie(nullptr);            // Disable automatic flushing of cout

    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c; // Input three integers

        int x = 0; // This will store the value we construct

        // Iterate from the highest bit (29) to lowest (0)
        for (int bit = 29; bit >= 0; bit--) {

            // Extract current bit of a, b, and c
            int abit = (a >> bit) & 1;
            int bbit = (b >> bit) & 1;
            int cbit = (c >> bit) & 1;

            int flip = 0; // Flag to decide whether to flip this bit

            // If current ordering condition is violated at this bit,
            // we consider flipping this bit in all three numbers
            if (a > b && abit > bbit) flip = 1;
            if (b > c && bbit > cbit) flip = 1;
            if (a > c && abit > cbit) flip = 1;

            // If flipping helps fix ordering, toggle this bit
            if (flip) {
                a ^= (1 << bit); // Flip bit in a
                b ^= (1 << bit); // Flip bit in b
                c ^= (1 << bit); // Flip bit in c
                x ^= (1 << bit); // Record this flip in x
            }
        }

        // After processing all bits:
        // Check if final condition a < b < c holds
        // If yes, print x (the number used for flipping)
        // Otherwise, print -1 (not possible)
        if (a < b && b < c)
            cout << x << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}
