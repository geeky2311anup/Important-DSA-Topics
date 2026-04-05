#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int bottles, int exchange) {
        
        // total bottles consumed initially (we drink all full bottles first)
        int totalDrunk = bottles;
        
        // empty bottles we currently have after drinking initial bottles
        int emptyBottles = bottles;

        // continue as long as we can exchange empty bottles for a new one
        while (emptyBottles >= exchange) {
            
            // we exchange 'exchange' empty bottles for 1 full bottle
            // then drink that bottle
            totalDrunk++;
            
            // after exchange:
            // - we lose 'exchange' empty bottles
            // - we gain 1 empty bottle after drinking the new one
            emptyBottles = emptyBottles - exchange + 1;
            
            // after each exchange, the requirement increases by 1
            exchange++;
        }

        // return total number of bottles we managed to drink
        return totalDrunk;
    }
};
