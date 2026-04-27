class Solution {

    // Computes absolute difference between number and its reversed form
    public int mirrorDistance(int value) {
        int reversedValue = getReversedValue(value);
        return Math.abs(value - reversedValue);
    }

    // Reverse number using string approach (different implementation)
    private int getReversedValue(int num) {
        String str = Integer.toString(num);
        StringBuilder sb = new StringBuilder(str);
        sb.reverse();

        return Integer.parseInt(sb.toString());
    }
}
