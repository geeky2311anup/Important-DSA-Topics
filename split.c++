#include<bits/stdc++.h>
# define pb push_back 
#define pii pair<int, int>
#define mp make_pair
# define ll long long int
 
using namespace std;
#include <iostream>
#include <string>
#include <utility>

 
const int maxt = 1e5;
const string newln = "\n", space = " ";
 
int main()
{   
    int t; cin >> t;
    while(t--){
        int w1, w2, x1, x2, m; cin >> w1 >> w2 >> x1 >> x2 >> m;
        int ans = (w2 - w1 >= x1 * m && w2 - w1 <= x2 * m ? 1 : 0); 
        cout << ans << endl;
    }
} 