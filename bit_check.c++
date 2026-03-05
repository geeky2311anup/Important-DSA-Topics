class Solution {
public:
    int smallestNumber(int n) {
        
        // Find the largest power of 2 exponent that fits in n
        // log2(n) gives the position of the highest set bit
        int d = (int)(log2(n));

        // Construct a number with all bits set to 1 up to that position
        // (1 << (d + 1)) creates a number like 1000... (d+1 bits)
        // Subtracting 1 converts it to 111... (d+1 ones)
        // Example:
        // n = 5 (101)
        // d = 2
        // (1 << 3) = 1000
        // 1000 - 1 = 111 = 7
        return (1 << (d + 1)) - 1;
    }
};
