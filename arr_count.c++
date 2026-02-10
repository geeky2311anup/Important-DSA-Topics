#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e4 + 10;
const int MAX_P = 15; // Maximum number of prime factors any number can have

// c[i][j] will store nCr values (combinations)
int c[MAX_N + MAX_P][MAX_P + 1];

// ps[x] will store the count of exponents of prime factors of x
// Example: 12 = 2^2 * 3^1 → ps[12] = {2, 1}
vector<int> ps[MAX_N];

// sieve[i] will store the smallest prime factor of i
int sieve[MAX_N];

class Solution {
public:
    Solution() {
        // If combinations already computed, skip precomputation
        if (c[0][0]) {
            return;
        }

        // Step 1: Build sieve to find smallest prime factor of each number
        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) { // i is prime
                for (int j = i; j < MAX_N; j += i) {
                    sieve[j] = i; // mark smallest prime factor
                }
            }
        }

        // Step 2: Precompute prime factor exponent counts for each number
        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int p = sieve[x]; // smallest prime factor
                int cnt = 0;

                // count how many times p divides x
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }

                // store exponent count
                ps[i].push_back(cnt);
            }
        }

        // Step 3: Precompute combinations using Pascal’s triangle
        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            c[i][0] = 1; // nC0 = 1
            for (int j = 1; j <= min(i, MAX_P); j++) {
                // Pascal's identity: nCr = (n-1)Cr + (n-1)C(r-1)
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }

    int idealArrays(int n, int maxValue) {
        long long ans = 0;

        // Try every possible ending value x
        for (int x = 1; x <= maxValue; x++) {
            long long mul = 1;

            // For each prime exponent of x
            for (int p : ps[x]) {
                // Number of ways to distribute exponent p
                // across n positions = C(n + p - 1, p)
                mul = (mul * c[n + p - 1][p]) % MOD;
            }

            // Add to total answer
            ans = (ans + mul) % MOD;
        }

        return ans;
    }
};
