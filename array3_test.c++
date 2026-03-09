#include <iostream>
using namespace std;

int main() {

    int T;  // Number of test cases
    cin >> T;

    // Loop through each test case
    while (T--) {

        int N, K;
        cin >> N >> K;
        // N = number of days
        // K = protein required per day

        int A[N];  // Array storing protein gained each day

        // Input protein gained for each day
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        long long proteinStored = 0;  // Stores leftover protein
        bool enoughProtein = true;    // Flag to check if requirement is satisfied
        int day = -1;                 // Stores the day when protein becomes insufficient

        // Simulate protein consumption day by day
        for (int i = 0; i < N; i++) {

            // Add protein gained on current day
            proteinStored += A[i];

            // Check if available protein is less than required
            if (proteinStored < K) {
                enoughProtein = false;   // Requirement not met
                day = i + 1;             // Store the failing day (1-based index)
                break;                   // Stop checking further days
            }

            // Consume K protein for the day
            proteinStored -= K;
        }

        // Output result
        if (enoughProtein) {
            cout << "YES" << endl;  // Protein requirement met for all days
        } else {
            cout << "NO " << day << endl;  // Protein shortage occurred on 'day'
        }
    }

    return 0;
}
