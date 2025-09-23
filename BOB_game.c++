#include <bits/stdc++.h>

using namespace std;
#include <iostream>


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int A, B;
    cin >> A >> B;
    for (int j = 1; j < 5000; j++) {
      if (j % 2 == 1) {
        A -= j;
        if (A < 0) { cout << "Bob\n"; break; }
      } else {
        B -= j;
        if (B < 0) { cout << "Limak\n"; break; }
      }
    }
  }
}
