#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> nums(n);
	    for(int i=0;i<n;i++){
	        cin>>nums[i];
	    }
	    bool isTrue = false;
	    int l=0,r=0;
	    for(int i=1;i<n;i++){
	        if(nums[i]<nums[i-1]){
	            isTrue = true;
	            l = i-1;
	            r = i;
	            break;
	        }
	    }
	    if(isTrue){
	        cout<<l+1<<" "<<r+1<<endl;
	    }else{
	        cout<<-1<<endl;
	    }
	}
	return 0;
}
