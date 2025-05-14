#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::count
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int gcd_val = arr[0];
        for (int i = 1; i < n; ++i) { // Start from the second element
            gcd_val = __gcd(gcd_val, arr[i]);
        }

        int gcd_count = std::count(arr.begin(), arr.end(), gcd_val); // Use std::count
        cout << (n - gcd_count) << endl;
    }
    return 0;
}
