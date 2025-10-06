#include<bits/stdc++.h>
using namespace std;
#include <iostream>


void solve()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];

	sort(a,a+3);

	cout<<(a[2]+a[1])<<"\n";
}

int main()
{
 
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  int t;
  cin>>t;

  while(t--)
    solve();

return 0;
}
