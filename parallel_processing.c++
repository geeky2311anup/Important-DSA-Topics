#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <iostream>


int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int numElements;
        cin >> numElements;

        int arr[numElements];
        long long int totalSum = 0;

        for (int i = 0; i < numElements; i++) {
            cin >> arr[i];
            totalSum += arr[i];
        }
        

        long long int minPossibleMaxSum = totalSum;
        long long int prefixSum = 0;

        for (int i = 0; i < numElements - 1; i++) {
            prefixSum += arr[i];
            minPossibleMaxSum = min(minPossibleMaxSum, max(prefixSum, totalSum - prefixSum));
        }

        cout << minPossibleMaxSum << endl;
    }
    return 0;
}
