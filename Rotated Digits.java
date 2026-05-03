class Solution {
    public int rotatedDigits(int n) {
        int result = 0;

        for (int i = 1; i <= n; i++) {
            if (isGoodNumber(i)) {
                result++;
            }
        }

        return result;
    }

    private boolean isGoodNumber(int num) {
        boolean hasDifferentDigit = false;

        while (num > 0) {
            int d = num % 10;

            // invalid digits
            if (d == 3 || d == 4 || d == 7) {
                return false;
            }

            // digits that change after rotation
            if (d == 2 || d == 5 || d == 6 || d == 9) {
                hasDifferentDigit = true;
            }

            num /= 10;
        }

        return hasDifferentDigit;
    }
}
