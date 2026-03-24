class Solution {
    public long maxMatrixSum(int[][] grid) {
        long total = 0; // Stores sum of absolute values of all elements
        int smallestAbs = Integer.MAX_VALUE; // Tracks smallest absolute value in matrix
        int negatives = 0; // Counts number of negative elements

        // Traverse the matrix
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                int val = grid[r][c];

                // Count how many negative numbers exist
                if (val < 0) negatives++;

                // Get absolute value of current element
                int absVal = Math.abs(val);

                // Update smallest absolute value seen so far
                smallestAbs = Math.min(smallestAbs, absVal);

                // Add absolute value to total sum
                total += absVal;
            }
        }

        // If number of negatives is even:
        // We can flip signs in pairs → make all elements positive
        if ((negatives & 1) == 0) {
            return total;
        }

        // If number of negatives is odd:
        // One element must remain negative
        // To minimize loss, keep the smallest absolute value negative
        // So subtract twice that value from total
        return total - 2L * smallestAbs;
    }
}
