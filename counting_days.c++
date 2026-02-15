#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <vector>


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        int busyDays = 0;
        int start = meetings[0][0], end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= end + 1) {
                // Merge overlapping meetings
                end = max(end, meetings[i][1]);
            } else {
                // Count merged busy days
                busyDays += (end - start + 1);
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }

        // Add last merged interval
        busyDays += (end - start + 1);

        return days - busyDays;
    }
};
