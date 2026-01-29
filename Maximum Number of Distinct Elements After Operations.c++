#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& arr, int k) {
        int n = arr.size();

        // Sort the array so we can greedily assign values
        // in increasing order without breaking distinctness
        sort(arr.begin(), arr.end());

        // lastUsed keeps track of the last distinct value we assigned
        // Initialize to very small so first element always works
        int lastUsed = INT_MIN;

        // Count of maximum distinct elements we can form
        int distinctCount = 0;

        // Traverse each element
        for (int i = 0; i < n; i++) {

            // Each element arr[i] can be adjusted within this range
            int lowLimit = arr[i] - k;
            int highLimit = arr[i] + k;

            // Case 1:
            // If last used value is smaller than the lowest allowed value,
            // we can safely assign lowLimit as a new distinct value
            if (lastUsed < lowLimit) {
                lastUsed = lowLimit;
                distinctCount++;
            }

            // Case 2:
            // If lastUsed is inside the allowed range,
            // we try to increment it by 1 to keep distinctness
            else if (lastUsed < highLimit) {
                lastUsed++;
                distinctCount++;
            }

            // Case 3:
            // If lastUsed >= highLimit,
            // no valid new distinct value can be assigned
            // so we skip this element
        }

        // Return the maximum number of distinct elements possible
        return distinctCount;
    }
};
