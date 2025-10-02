#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int bottles, int exchange) {
        int totalDrunk = bottles;
        int emptyBottles = bottles;

        while (emptyBottles >= exchange) {
            // drink one more after exchanging
            totalDrunk++;
            // update empty bottles after exchange
            emptyBottles = emptyBottles - exchange + 1;
            exchange++;
        }

        return totalDrunk;
    }
};
