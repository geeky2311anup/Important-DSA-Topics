#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <cmath>


void findMaximumPairs() {
    string students;
    cin >> students;
    int totalStudents = students.size();
    vector<int> dp(totalStudents);
    
    dp[0] = 0;

    for (int i = 1; i < totalStudents; i++) {
        if (students[i] == students[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = max(dp[i - 1], (i >= 2 ? dp[i - 2] + 1 : 1));
        }
    }

    cout << dp[totalStudents - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        findMaximumPairs();
    }
    return 0;
}
