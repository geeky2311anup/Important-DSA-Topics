#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int maxIncreasingSubarrays(vector<int>& nums) {
        int nsz = nums.size();
        if (nsz == 0) return 0;

        int bestK = 0;      // best answer found so far
        int prevRun = 0;    // length of the increasing run immediately before the current one
        int currRun = 1;    // length of the current increasing run (at least 1 for a single element)

        for (int i = 1; i < nsz; ++i) {
            if (nums[i] > nums[i - 1]) {
                // extend the current strictly increasing run
                ++currRun;
            } else {
         
                bestK = max(bestK, currRun / 2);
                bestK = max(bestK, min(prevRun, currRun));

                // shift runs: current becomes previous, and start a new current run
                prevRun = currRun;
                currRun = 1;
            }
        }

        
        bestK = max(bestK, currRun / 2);
        bestK = max(bestK, min(prevRun, currRun));

        return bestK;
    }
};
