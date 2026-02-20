#include<bits/stdc++.h>
using namespace std;

// Fast I/O macro
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

//_____________________________________________________________

void solve() {
    int n, k;
    cin >> n >> k;   // Input two integers n and k
    
    /*
        __gcd(k, n) gives the Greatest Common Divisor (GCD) of k and n.
        
        Formula for LCM:
            LCM(a, b) = (a * b) / GCD(a, b)
        
        Here we compute:
            n / gcd(k, n)
        
        This is mathematically equivalent to:
            LCM(n, k) / k
        
        Because:
            LCM(n, k) = (n * k) / gcd(n, k)
            => LCM(n, k) / k = n / gcd(n, k)
        
        So the variable name "lcm" here actually represents:
            LCM(n, k) / k
    */
    
    int lcm = n / __gcd(k, n);
    
    // Output the computed result
    cout << lcm << endl;
}

int32_t main()
{
    _z;  // Enable fast input-output
    
    int t = 1;
    cin >> t;  // Number of test cases
    
    // Process each test case
    while(t--) {
        solve();
    }
}




