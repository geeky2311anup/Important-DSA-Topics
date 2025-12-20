class Solution {

    private boolean columnIsNonDecreasing(String[] words, int idx) {
        for (int r = 1; r < words.length; r++) {
            if (words[r].charAt(idx) < words[r - 1].charAt(idx)) {
                return false;
            }
        }
        return true;
    }

    public int minDeletionSize(String[] strs) {
        int remove = 0;
        int cols = strs[0].length();

        for (int c = 0; c < cols; c++) {
            if (!columnIsNonDecreasing(strs, c)) {
                remove++;
            }
        }
        return remove;
    }
}
