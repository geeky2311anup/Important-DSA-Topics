class Solution {
public:
    int findClosest(int numA, int numB, int target) {
        int diffA = abs(numA - target);
        int diffB = abs(numB - target);

        if (diffA < diffB) {         //if b>a
            return 1;   // numA is closer
        } else if (diffA > diffB) {
            return 2;   // numB is closer
        } else {
            return 0;   // both are equally close
        }
    }
};
