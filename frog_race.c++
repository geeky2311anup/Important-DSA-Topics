#include <bits/stdc++.h>
using namespace std;


void solve(){
  int grps_w=0,grps_b=0;


  int n,i;
  string s;
  cin >> n >> s;

  for(i=0;i<n;i++){
      
      assert(s[i]=='B' || s[i]=='W');

    int j=i+1;

    if(s[i]=='W'){
      grps_w++;

      while(j<n && s[j]==s[i]){
        j++;
      }
    } else {
      grps_b++;
      while(j<n && s[j]==s[i]){
        j++;
      }
    }

    i=j-1;
  }

  cout << min(grps_b,grps_w) << "\n";
  

}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  //A soln

   #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      freopen("error.txt","w",stderr);
    #endif


  int tests;
  cin >> tests;

  while(tests--){
    solve();
  }

  
}
