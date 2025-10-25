#include <bits/stdc++.h>
using namespace std;

void process() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;

    int oddCount = count_if(nums.begin(), nums.end(), [](int x){ return x & 1; });
    cout << (oddCount == 1 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) process();
    return 0;
}
