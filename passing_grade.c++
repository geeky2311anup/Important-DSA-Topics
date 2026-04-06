#include <bits/stdc++.h>
using namespace std;

// Using unsigned long long to handle up to 64-bit integers
using ull = unsigned long long;
using ll = long long;

/**
 * Calculates the rank of the XOR basis of the given array.
 * The rank represents the number of linearly independent elements 
 * (in terms of XOR) in the set.
 */
int basisRank(vector<ull> arr) {
    int n = arr.size();
    int rank = 0;

    // Standard Gaussian Elimination for XOR Basis
    for (int bit = 63; bit >= 0; --bit) {
        int idx = -1;
        // Find an element that has the current 'bit' set
        for (int i = rank; i < n; i++) {
            if ((arr[i] >> bit) & 1ULL) {
                idx = i;
                break;
            }
        }

        // If no element has this bit set, move to the next bit
        if (idx == -1) continue;

        // Bring the element to the 'rank' position
        swap(arr[rank], arr[idx]);

        // Eliminate this bit from all other elements to maintain independence
        for (int j = 0; j < n; ++j) {
            if (j != rank && ((arr[j] >> bit) & 1ULL)) {
                arr[j] ^= arr[rank];
            }
        }
        rank++; // One more independent vector found
    }
    return rank;
}

ll solveCase(int n, int k, const vector<ull>& vals) {
    // Calculate the XOR sum of all elements in the input
    ull totalXor = 0;
    for (auto x : vals) totalXor ^= x;

    // r1 is the rank of the original values
    int r1 = basisRank(vals);

    // Special Case: If k equals n, the only possible XOR sums are 
    // 0 and the total XOR sum of all elements.
    if (k == n) return totalXor ? 2 : 1;

    // If k is odd, we can reach any value representable by the basis.
    // The number of distinct values is 2^rank.
    if (k % 2 != 0) return 1LL << r1;

    /** * If k is even:
     * We use a trick to check parity constraints. 
     * By shifting left and adding 1, we treat each number as (value, 1).
     * This helps track if an XOR sum is formed by an even or odd number of elements.
     */
    vector<ull> transformed;
    transformed.reserve(n);
    for (auto x : vals) {
        transformed.push_back((x << 1) | 1ULL);
    }

    // r2 helps determine if the "all-ones" vector is linearly independent 
    // from the values in terms of parity.
    int r2 = basisRank(transformed);

    // If r2 == r1 + 1, it means parity doesn't restrict the values reachable.
    // Otherwise, the dimension is reduced.
    int d = (r2 == r1 + 1) ? r1 : max(0, r1 - 1);
    
    return 1LL << d;
}

void process() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<ull> vals(n);
    for (auto& x : vals) cin >> x;
    cout << solveCase(n, k, vals) << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        process();
    }
    return 0;
}
