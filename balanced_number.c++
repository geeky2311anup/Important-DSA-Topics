class Solution {
    static bool isBalanced(int x) {
        int cnt[10] = {0};
        while (x > 0) {
            int d = x % 10;
            cnt[d]++;
            x /= 10;
        }
        // For every digit that appears, its count must equal the digit.
        for (int d = 0; d <= 9; ++d) {
            if (cnt[d] != 0 && cnt[d] != d) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        for (int cur = n + 1;; ++cur) {
            if (isBalanced(cur)) return cur;
        }
    }
};
