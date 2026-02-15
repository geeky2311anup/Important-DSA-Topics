#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <utility>
#include <vector>


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--){
		int D, L, R; cin >> D >> L >> R;
		if(D < L) cout << "Too Early\n";
		else if(L <= D and D <= R) cout << "Take second dose now\n";
		else cout << "Too Late\n";;
	}

	return 0;
}