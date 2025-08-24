#include <iostream>
using namespace std;

int Tc;

int main(){
	cin>>Tc;
	for(int j=0;j<Tc;j++){
		// process a single test-case here
		int N,K,sol=0;
		cin>>N>>K;
		for(int j=0;j<N;j++){
			int T,D;
			cin>>T>>D;
			if(T<K){
				K= K - T;
			} else {
				sol += (T-K)*D;
				K=0;
			}
		}
		cout<<sol<<endl;
	}
}