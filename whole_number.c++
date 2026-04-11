#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    // Fast I/O optimization
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;  // number of test cases

    while(t--)
    {
        int n, k;
        cin >> n >> k;  // input values

        // If k is 0, modulo operation is undefined
        // So we directly return n
        if(k == 0)
        {
            cout << n << "\n";
            continue;  // move to next test case
        }

        // Otherwise, print remainder when n is divided by k
        cout << (n % k) << "\n";
    }

    return 0;
}
