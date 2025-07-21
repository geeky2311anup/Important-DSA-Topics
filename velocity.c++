#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
 
int main(){
    fastio;
 
    int t; 
    cin>>t;
 
    while(t--){
        long long int u, v, a, s;
        cin>>u>>v>>a>>s;
 
        if(v * v >= u * u - 2 * a * s) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}