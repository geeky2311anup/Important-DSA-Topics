#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>


int main(){
	int T;
	scanf("%d",&T);

	for(int cs=1;cs<=T;cs++){
	    int N;
	    scanf("%d",&N);

	    string a,b;
	    cin>>a>>b;

	    sort(a.begin(),a.end());
	    sort(b.begin(),b.end());
	    cout<< ((a==b) ? "YES" : "NO") <<endl;
	}
}