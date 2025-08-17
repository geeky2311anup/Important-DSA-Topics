#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	#ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(NULL));
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,s;
	    cin>>n>>x>>s;
	    int currAns=x;
	    int a,b;
	    while(s--)
	    {
	        cin>>a>>b;
	        if(a==currAns)
	            currAns=b;
	        else if(b==currAns)
	            currAns=a;
	    }
	    cout<<currAns<<endl;
	}
	return 0;
}
T
i
m
e
