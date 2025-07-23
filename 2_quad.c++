#include<bits/stdc++.h>
using namespace std;

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
		int N, A, B, C; cin >> N >> A >> B >> C;
		if(min(B, A+C) >= N) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}