#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& arr, int k, int ops) {
        if (arr.empty()) return 0;

        sort(arr.begin(), arr.end());
        int n = arr.size();

        unordered_map<int, int> count;
        for (int num : arr) count[num]++;

        int result = 1;

        for (auto &p : count) {
            int val = p.first;
            int freq = p.second;

            int low = val - k;
            int high = val + k;

            int leftIdx = lower_bound(arr.begin(), arr.end(), low) - arr.begin();
            int rightIdx = upper_bound(arr.begin(), arr.end(), high) - arr.begin();

            int inRange = rightIdx - leftIdx;
            int diff = inRange - freq;
            int canUse = min(diff, ops);

            result = max(result, freq + canUse);
        }

        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (left <= right && arr[right] - arr[left] > 2 * k) left++;
            int windowSize = right - left + 1;
            result = max(result, min(windowSize, ops));
        }

        return result;
    }
};
