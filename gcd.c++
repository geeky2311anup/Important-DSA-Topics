#include<bits/stdc++.h>
using namespace std;
#include <iostream>


#define _z ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

//______________________________z_____________________________

void solve() {
    int n, k;
    cin >> n >> k;
    
    int lcm = n / __gcd(k, n);
    
    cout << lcm << endl;
}

int32_t main()
{
    _z;
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}
