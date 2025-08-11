#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> songs(N);
        for (int i = 0; i < N; i++) cin >> songs[i];

        int K;
        cin >> K;
        long long uncleJohny = songs[K - 1]; // original position

        sort(songs.begin(), songs.end());

        // find new position (1-indexed)
        int newPos = find(songs.begin(), songs.end(), uncleJohny) - songs.begin() + 1;
        cout << newPos << "\n";
    }
    return 0;
}
