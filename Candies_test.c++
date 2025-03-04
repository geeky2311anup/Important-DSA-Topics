#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        long long sumA = 0;
        
        // Read the array and compute its sum.
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            sumA += A[i];
        }
        
        // Sort the array to assign the smallest possible target to each element.
        sort(A.begin(), A.end());
        
        bool possible = true;
        for (int i = 0; i < N; i++) {
            // For the i-th smallest element, the smallest available target is (i+1).
            if (A[i] > i + 1) {
                possible = false;
                break;
            }
        }
        
        if (!possible) {
            cout << -1 << "\n";
        } else {
            // The sum of numbers from 1 to N.
            long long targetSum = (long long)N * (N + 1) / 2;
            cout << (targetSum - sumA) << "\n";
        }
    }
    
    return 0;
}
