#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
 
void solve()
{
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  //minimum moves required
  int X = abs(c - a) + abs(d - b);
  // Checking minimum and parity condition
  if (k >= X && k % 2 == X % 2)
  {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
 
 
}
int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int t;
  cin >> t;
 
  while (t--)
    solve();
 
  return 0;
}