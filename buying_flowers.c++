#include <bits/stdc++.h>
using namespace std;

// Using long long with a shorter alias for convenience
using int64 = long long;

/*
    Fast I/O setup.
    Disables synchronization with C stdio and unties cin from cout
    to make input/output operations faster (useful in competitive programming).
*/
inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

/*
    Function to solve one test case.
*/
void solve_case() {

    // Read input value x
    int64 x;

    // Safety check in case input stream fails
    if (!(cin >> x)) return;

    /*
        Handle small edge cases directly.

        x = 2  -> answer = 4
        x = 3  -> answer = 5

        These are base cases where the general formula below
        might not work properly or would require extra handling.
    */
    if (x == 2) {
        cout << 4 << '\n';
        return;
    }

    if (x == 3) {
        cout << 5 << '\n';
        return;
    }

    /*
        Divide x by 3 because groups of size 3 give optimal contribution.

        q = number of full groups of 3
        r = remainder when dividing by 3
    */
    int64 q = x / 3;
    int64 r = x % 3;

    // Variable to store the final answer
    int64 ans = 0;

    /*
        Case 1: remainder = 0
        x is perfectly divisible by 3.

        Each group contributes 5 to the answer.
        So total contribution = q * 5
    */
    if (r == 0) {
        ans = q * 5;
    }

    /*
        Case 2: remainder = 2

        We have q groups of 3 and one extra 2.

        Each group of 3 contributes 5
        The extra 2 contributes 4
    */
    else if (r == 2) {
        ans = q * 5 + 4;
    }

    /*
        Case 3: remainder = 1

        If we keep q groups of 3, we will be left with 1,
        which is not optimal.

        Instead:
        - Convert one group of 3 into two groups of 2.

        Steps:
        1. Use (q - 1) groups of 3
        2. Remaining numbers form groups of 2
    */
    else { // r == 1

        // Ensure we actually have a group of 3 to convert
        if (q >= 1) {

            // Number of groups of 3 we keep
            int64 use = q - 1;

            /*
                Remaining elements after using (q - 1) groups of 3
            */
            int64 remaining = x - use * 3;

            /*
                Each remaining pair contributes 4
            */
            ans = use * 5 + (remaining / 2) * 4;
        }

        /*
            Fallback case for very small x
            (Though usually x >= 2 in valid test cases)
        */
        else {
            ans = 4;
        }
    }

    // Output the computed answer
    cout << ans << '\n';
}

/*
    Main driver function.
*/
int main() {

    // Enable fast input/output
    fast_io();

    // Number of test cases
    int T;
    cin >> T;

    // Process each test case
    while (T--) {
        solve_case();
    }

    return 0;
}
