#include <iostream>
using namespace std;
#include <string>


void solve() {
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;

    // Count '0's and '1's in both strings
    int countA_0 = 0, countA_1 = 0;
    int countB_0 = 0, countB_1 = 0;

    for (char c : A) {
        if (c == '0') countA_0++;
        else countA_1++;
    }

    for (char c : B) {
        if (c == '0') countB_0++;
        else countB_1++;
    }

    // If counts match, transformation is possible
    if (countA_0 == countB_0 && countA_1 == countB_1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
