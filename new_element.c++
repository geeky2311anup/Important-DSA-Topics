#include <iostream>
#include <vector>
#include <numeric> // For std::gcd

using namespace std;

// Function to calculate the greatest common divisor
int calculateGCD(int a, int b) {
    return (b == 0) ? a : calculateGCD(b, a % b);
}

// Function to solve the problem for a single test case
void solveTestCase() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> prefixGCD(n);
    vector<int> suffixGCD(n);

    int allGCD = v[0];
    prefixGCD[0] = v[0];
    suffixGCD[n - 1] = v[n - 1];

    for (int i = 1; i < n; ++i) {
        allGCD = calculateGCD(allGCD, v[i]);
        prefixGCD[i] = calculateGCD(prefixGCD[i - 1], v[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
        suffixGCD[i] = calculateGCD(suffixGCD[i + 1], v[i]);
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int currentGCD;
        if (i == 0) {
            currentGCD = suffixGCD[i + 1];
        } else if (i == n - 1) {
            currentGCD = prefixGCD[i - 1];
        } else {
            currentGCD = calculateGCD(prefixGCD[i - 1], suffixGCD[i + 1]);
        }

        if (currentGCD != 1) {
            ++answer;
        }
    }

    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solveTestCase();
    }
    return 0;
}
