#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int maxIncreasingSubarrays(vector<int>& nums) {
        // Get the size of the input array
        int nsz = nums.size();

        // Edge case: if array is empty, no subarrays exist
        if (nsz == 0) return 0;

        // bestK:
        // Stores the maximum valid k found so far.
        // k represents the length of two adjacent increasing subarrays.
        int bestK = 0;

        // prevRun:
        // Length of the previous strictly increasing segment
        // (the run just before the current one).
        int prevRun = 0;

        // currRun:
        // Length of the current strictly increasing segment.
        // Initialized to 1 because a single element is itself a run.
        int currRun = 1;

        // Traverse the array starting from index 1
        for (int i = 1; i < nsz; ++i) {

            // If current element is greater than previous,
            // we are still inside an increasing run.
            if (nums[i] > nums[i - 1]) {
                // Extend the current increasing run
                ++currRun;
            } 
            else {
                // The increasing run has ended at index i-1.

                // Case 1:
                // The current run alone may contain two subarrays of length k.
                // Example: run length = 6 → possible k = 3.
                bestK = max(bestK, currRun / 2);

                // Case 2:
                // Combine previous run and current run.
                // We can take k from the smaller of the two.
                // Example:
                // prevRun = 4, currRun = 3 → k = 3
                bestK = max(bestK, min(prevRun, currRun));

                // Now shift runs:
                // current run becomes previous
                prevRun = currRun;

                // Start a new run from current element
                currRun = 1;
            }
        }

        // After the loop, we must process the last run,
        // because the loop only processes when a break occurs.

        // Case 1: split last run into two parts
        bestK = max(bestK, currRun / 2);

        // Case 2: combine last run with previous run
        bestK = max(bestK, min(prevRun, currRun));

        // Return the maximum k found
        return bestK;
    }
};
