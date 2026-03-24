#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& arr, int k, int ops) {
        // If array is empty, frequency is 0
        if (arr.empty()) return 0;

        // Sort the array to use binary search and sliding window
        sort(arr.begin(), arr.end());
        int n = arr.size();

        // Count frequency of each number
        unordered_map<int, int> count;
        for (int num : arr) count[num]++;

        // At least one element will always exist
        int result = 1;

        // Try making each unique value the target value
        for (auto &p : count) {
            int val = p.first;   // target value
            int freq = p.second; // its current frequency

            // Allowed range after operations
            int low = val - k;
            int high = val + k;

            // Find indices of elements within [low, high]
            int leftIdx = lower_bound(arr.begin(), arr.end(), low) - arr.begin();
            int rightIdx = upper_bound(arr.begin(), arr.end(), high) - arr.begin();

            // Number of elements in this range
            int inRange = rightIdx - leftIdx;

            // Elements that can be converted to 'val'
            int diff = inRange - freq;

            // We can only use up to 'ops' operations
            int canUse = min(diff, ops);

            // Update maximum frequency
            result = max(result, freq + canUse);
        }

        // Sliding window approach:
        // Try forming a group where all numbers can be converted
        int left = 0;
        for (int right = 0; right < n; ++right) {

            // Shrink window if difference exceeds allowed limit
            while (left <= right && arr[right] - arr[left] > 2 * k) 
                left++;

            int windowSize = right - left + 1;

            // We can only convert up to 'ops' elements
            result = max(result, min(windowSize, ops));
        }

        return result;
    }
};
