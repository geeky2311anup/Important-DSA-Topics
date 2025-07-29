#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forn(i,e) for(ll i = 0; i < e; i++)

void solve()
{
	ll n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    if(sum%2)
    {
        cout<<n-1<<endl;
    }
    else
    {
        cout<<n<<endl;
    }
}

int main()
{
	ll t=1;
	cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}