#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int basisRank(vector<ull> arr) {
    int n = arr.size(), rank = 0;
    for (int bit = 63; bit >= 0; --bit) {
        int idx = rank;
        while (idx < n && ((arr[idx] >> bit) & 1ULL) == 0) ++idx;
        if (idx == n) continue;
        swap(arr[rank], arr[idx]);
        for (int j = 0; j < n; ++j)
            if (j != rank && ((arr[j] >> bit) & 1ULL))
                arr[j] ^= arr[rank];
        ++rank;
    }
    return rank;
}

ll solveCase(int n, int k, const vector<ull>& vals) {
    ull total = 0;
    for (auto x : vals) total ^= x;
    int r1 = basisRank(vals);
    if (k == n) return total ? 2 : 1;
    if (k % 2) return 1LL << r1;

    vector<ull> transformed;
    transformed.reserve(n);
    for (auto x : vals) transformed.push_back((x << 1) | 1ULL);
    int r2 = basisRank(transformed);
    int d = (r2 == r1 + 1) ? r1 : max(0, r1 - 1);
    return 1LL << d;
}

void process() {
    int n, k;
    cin >> n >> k;
    vector<ull> vals(n);
    for (auto& x : vals) cin >> x;
    cout << solveCase(n, k, vals) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) process();
}
