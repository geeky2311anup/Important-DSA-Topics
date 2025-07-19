#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	   int a,b,p,q;
	   cin >> a >> b >> p >> q;
	   
	   if (p%a != 0 || q%b != 0) {
	      cout << "NO\n";
	   } else if (p/a == q/b || p/a == q/b - 1 || p/a == q/b + 1) {
	      cout << "YES\n";
	   } else {
	      cout << "NO\n";
	   }
	}
	return 0;
}
