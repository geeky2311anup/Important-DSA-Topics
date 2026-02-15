#include <bits/stdc++.h>
using namespace std;
#include <iostream>


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int prices[n];
        for(int i=0;i<n;i++){
            cin>>prices[i];
        }
        long long save = 0;

        for (int i = 0; i < n; i++) {
            if (prices[i] >= y) {
                
                save += y;
            } else {
                save += prices[i];
            }
        }

        if (save > x) {
            cout << "COUPON" << endl;
        } else {
            cout << "NO COUPON" << endl;
        }
    }

    return 0;
}
