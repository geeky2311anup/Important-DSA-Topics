#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <iostream>

 
void mainSolve()
{
  int n = 0;
  string s;
  cin >> n >> s;
 
  int n_0 = 0, n_1 = 0;
  for (char c : s)
  {
    if (c == '1')
      n_1++;
    else
      n_0++;
  }
  int ans = 2 * min(n_0, n_1) + ((n_1 == n_0) ? 0 : 1);
  cout << ans << endl;
}
 
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    mainSolve();
  }
  return 0;
}
