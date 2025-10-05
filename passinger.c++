#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int numPlayers;
        cin >> numPlayers;

        vector<int> scores(numPlayers);
        for (int i = 0; i < numPlayers; ++i) {
            cin >> scores[i];
        }

        int chefScore = scores[0];
        int countPassed = 0;

        // Count how many players have score >= chef’s score
        for (int i = 1; i < numPlayers; ++i) {
            if (scores[i] >= chefScore) {
                ++countPassed;
            }
        }

        // Chef always passes (so +1)
        cout << (countPassed + 1) << '\n';
    }

    return 0;
}
