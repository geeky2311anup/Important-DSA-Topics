#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        long long totalSum = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            totalSum += arr[i];
        }
        

        sort(arr.begin(), arr.end());

        long long sumOfKSmallest = 0, sumOfKLargest = 0;


        for (int i = 0; i < k; i++) {
            sumOfKSmallest += arr[i];
            sumOfKLargest += arr[n - 1 - i];
        }

        long long diff1 = abs(sumOfKSmallest - (totalSum - sumOfKSmallest));
        long long diff2 = abs(sumOfKLargest - (totalSum - sumOfKLargest));

        cout << max(diff1, diff2) << endl;
    }
    return 0;
}