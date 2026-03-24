import java.util.*;

class Solution {
    public int[][] minAbsDiff(int[][] matrix, int k) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int[][] result = new int[rows - k + 1][cols - k + 1];

        for (int top = 0; top <= rows - k; top++) {

            TreeMap<Integer, Integer> freq = new TreeMap<>();

            // Build initial k x k window for first column
            for (int r = top; r < top + k; r++) {
                for (int c = 0; c < k; c++) {
                    freq.put(matrix[r][c], freq.getOrDefault(matrix[r][c], 0) + 1);
                }
            }

            for (int left = 0; left <= cols - k; left++) {

                // Compute minimum absolute difference
                if (freq.size() <= 1) {
                    result[top][left] = 0;
                } else {
                    int minDiff = Integer.MAX_VALUE;
                    Integer prev = null;

                    for (int val : freq.keySet()) {
                        if (prev != null) {
                            minDiff = Math.min(minDiff, val - prev);
                        }
                        prev = val;
                    }

                    result[top][left] = minDiff;
                }

                // Slide window to the right
                if (left < cols - k) {
                    for (int r = top; r < top + k; r++) {

                        int removeVal = matrix[r][left];
                        int addVal = matrix[r][left + k];

                        // Remove element
                        freq.put(removeVal, freq.get(removeVal) - 1);
                        if (freq.get(removeVal) == 0) {
                            freq.remove(removeVal);
                        }

                        // Add element
                        freq.put(addVal, freq.getOrDefault(addVal, 0) + 1);
                    }
                }
            }
        }

        return result;
    }
}
