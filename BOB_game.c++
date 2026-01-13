#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  // Fast I/O because patience is finite
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // Output formatting (mostly useless here, but template habits die hard)
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  // Number of test cases
  cin >> T;

  // Process each test case
  for (int i = 0; i < T; i++) {
    int A, B;
    // A = Bob's initial power
    // B = Limak's initial power
    cin >> A >> B;

    // j represents the move number and also the amount subtracted
    for (int j = 1; j < 5000; j++) {

      // Odd move: Bob loses j
      if (j % 2 == 1) {
        A -= j;

        // If Bob can't make the move, Limak wins
        if (A < 0) {
          cout << "Bob\n";
          break;
        }
      }
      // Even move: Limak loses j
      else {
        B -= j;

        // If Limak can't make the move, Bob wins
        if (B < 0) {
          cout << "Limak\n";
          break;
        }
      }
    }
  }
}
