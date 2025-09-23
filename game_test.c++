#include <bits/stdc++.h>
using namespace std;
#include <vector>


class Solution {
public:
    int minOperations(vector<int>& nums) {
        deque<int> flipQueue;
        int operations = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            // Remove outdated flips that are beyond the 3-element window
            if (!flipQueue.empty() && flipQueue.front() + 2 < i) {
                flipQueue.pop_front();
            }

            // Determine if we need to flip at this position
            if ((nums[i] + flipQueue.size()) % 2 == 0) {
                if (i + 2 >= n) return -1; // Not enough space to flip a group of 3

                // Perform the flip
                operations++;
                flipQueue.push_back(i);
            }
        }

        return operations;
    }
};
