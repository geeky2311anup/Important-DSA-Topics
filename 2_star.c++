#include<bits/stdc++.h>
using namespace std;

void solve(){
  int l,r; cin>>l>>r;
  l=2*l;
  r=2*r;

  int ans=r-l+1;

  cout<<ans<<"\n";
}

int main(){
  int t; cin>>t;
  while(t--){
    solve();
  }

return 0;

}