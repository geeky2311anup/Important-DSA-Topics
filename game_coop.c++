#include <bits/stdc++.h>

// Macro definitions for convenience
#define ll long long                          // Alias for long long
#define sz(x) ((int) (x).size())               // Get size of container as int
#define all(x) (x).begin(), (x).end()          // Shortcut to get begin and end iterators
#define vi vector<int>                         // Alias for vector of integers
#define pii pair<int, int>                     // Alias for pair of integers
#define rep(i, a, b) for(int i = (a); i < (b); i++)  // Loop macro from a to b-1

using namespace std;

// Min-priority queue template alias
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    // Fast input-output optimization
    ios::sync_with_stdio(false);
    cin.tie(0);

    int te;          // Number of test cases
    cin >> te;

    // Process each test case
    while(te--) {
        int n;
        cin >> n;    // Input value for current test case

        // Output (n + 1) / 2
        // This effectively calculates the ceiling of n/2
        // For example:
        // n = 4 -> 2
        // n = 5 -> 3
        cout << (n + 1) / 2 << '\n';
    }

    return 0;  // Indicate successful execution
}
