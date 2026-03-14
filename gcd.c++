#include<bits/stdc++.h>
using namespace std;

// Fast input/output macro
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL);

// Replace endl with "\n" for faster output
#define endl "\n"

//____________________________________________________________

// Function to solve one test case
void solve() {
    int n, k;
    
    // Read input values
    cin >> n >> k;
    
    /*
        Compute the value using GCD.

        __gcd(k, n) gives the greatest common divisor of k and n.

        n / gcd(k, n) gives the number of steps required for
        k to cycle through n in modular arithmetic.

        This value is printed as the result.
    */
    int result = n / __gcd(k, n);
    
    // Output the answer
    cout << result << endl;
}

int32_t main()
{
    // Enable fast I/O
    _z;

    int t = 1;
    
    // Number of test cases
    cin >> t;

    // Process each test case
    while(t--) {
        solve();
    }
}
