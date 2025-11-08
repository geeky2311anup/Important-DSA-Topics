link -> https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/?envType=daily-question&envId=2025-11-08

class Solution {
    public int minimumOneBitOperations(int num) {
        int ans = 0;
        int val = num;
        while (val != 0) {
            ans ^= val;
            val >>= 1;
        }
        return ans;
    }
}
