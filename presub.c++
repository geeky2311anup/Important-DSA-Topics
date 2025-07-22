#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
 
int main(){
    fastio;
 
    int t;
    cin>>t;
    while(t--){
        long long int n, x, s, r;
        cin>>n>>x;
        long long int ans = -1e9;
        for(int i = 0; i < n; i++){
            cin>>s>>r;
            if(s <= x) ans = max(ans, r);
        }
        cout<<ans<<endl;
        
    }
 
    return 0;
}