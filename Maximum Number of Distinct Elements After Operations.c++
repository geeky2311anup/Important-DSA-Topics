#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());  // sort to handle range adjustments smoothly

        int lastUsed = INT_MIN;  // track the last distinct number placed
        int distinctCount = 0;

        for (int i = 0; i < n; i++) {
            // find the minimum possible starting value within allowed adjustment range
            int lowLimit = arr[i] - k;
            int highLimit = arr[i] + k;

            if (lastUsed < lowLimit) {
                // we can freely assign the smallest valid value
                lastUsed = lowLimit;
                distinctCount++;
            } 
            else if (lastUsed < highLimit) {
                // we can still move 1 step ahead within the valid range
                lastUsed++;
                distinctCount++;
            }
            // else → if lastUsed >= highLimit, skip (cannot create new distinct number)
        }

        return distinctCount;
    }
};
