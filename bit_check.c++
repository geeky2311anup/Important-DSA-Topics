

class Solution {
public:
    int smallestNumber(int n) {
        int d = (int)(log2(n));
        return (1<<d+1)-1;
    }
};
