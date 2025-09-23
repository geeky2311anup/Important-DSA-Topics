#include <iostream>

using namespace std;

using namespace std;
void solve()
{
    int n,x;
    cin>>n>>x;
    cout<<(x%(n+1))<<'\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}