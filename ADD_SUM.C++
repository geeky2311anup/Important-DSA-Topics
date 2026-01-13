#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, N, K;
    
    // Read number of test cases
    cin >> T;

    // Loop through each test case
    while (T--) {
        // N = number of girls
        // K = window size (number of consecutive girls to consider)
        cin >> N >> K;

        vector<int> girls(N);

        int currentImpressed = 0; // sum of current window
        int maxImpressed = 0;     // maximum sum found so far

        // Read the values and calculate sum of first K elements
        for (int i = 0; i < N; i++) {
            cin >> girls[i];

            // Add only the first K elements to the initial window sum
            if (i < K) {
                currentImpressed += girls[i];
            }
        }

        // Initialize maximum with the first window sum
        maxImpressed = currentImpressed;

        // Slide the window from index K to N-1
        for (int i = K; i < N; i++) {
            // Remove the element going out of the window
            // Add the new element coming into the window
            currentImpressed = currentImpressed - girls[i - K] + girls[i];

            // Update maximum sum if current window is better
            maxImpressed = max(maxImpressed, currentImpressed);
        }

        // Output the maximum impressed value for this test case
        cout << maxImpressed << endl;
    }

    return 0;
}
