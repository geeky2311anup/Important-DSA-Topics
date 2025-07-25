#include<bits/stdc++.h>
using namespace std;

#define _z ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

//______________________________z_____________________________

void solve() {
    double s, a, b, c;
    cin >> s >> a >> b >> c;
    double price = s + (s*c) / 100;
    if(price <= b && price >= a) cout << "YES" << endl;
    else cout << "NO" << endl;
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