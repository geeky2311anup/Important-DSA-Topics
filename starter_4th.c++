#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    cin >> testCount;

    while (testCount--) {
        int size, dummy;
        cin >> size >> dummy; // second input 'd' is unused

        vector<long long> arr(size + 1);
        for (int i = 1; i <= size; ++i) {
            cin >> arr[i];
        }

        long long result = arr[1];
        for (int i = 2; i <= size; ++i) {
            if (i % 2 == 0)
                result = max(result, arr[i]);
            else
                result = min(result, arr[i]);
        }

        cout << result << '\n';
    }

    return 0;
}
