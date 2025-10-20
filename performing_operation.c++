#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& ops) {
        int value = 0;

        for (const string& operation : ops) {
            if (operation == "++X" || operation == "X++") {
                ++value;
            } else {
                --value;
            }
        }

        return value;
    }
};
