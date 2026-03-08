#include <iostream>
using namespace std;

int Tc;  // Number of test cases

int main() {
    cin >> Tc;  // Read number of test cases

    // Loop through each test case
    for (int j = 0; j < Tc; j++) {

        int N, K, sol = 0;

        // N = number of items/tasks
        // K = free time/limit before penalty starts
        cin >> N >> K;

        // Process each of the N entries
        for (int j = 0; j < N; j++) {
            int T, D;

            // T = time required
            // D = penalty per unit time after K is exhausted
            cin >> T >> D;

            // If remaining free time K can cover T
            if (T < K) {
                // Reduce available free time
                K = K - T;
            } 
            else {
                // If T exceeds remaining free time
                // Calculate penalty for extra time
                sol += (T - K) * D;

                // Free time is now fully used
                K = 0;
            }
        }

        // Output total penalty for this test case
        cout << sol << endl;
    }
}
