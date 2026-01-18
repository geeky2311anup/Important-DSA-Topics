class Solution {
    public int minDeletionSize(String[] strs) {

        // Number of rows (strings)
        int rows = strs.length;

        // Number of columns (length of each string)
        int cols = strs[0].length();

        /*
           keep[j] represents the length of the longest valid
           non-decreasing column sequence ending at column j.
        */
        int[] keep = new int[cols];

        // Initialize all values to 1 because each column alone is always valid
        Arrays.fill(keep, 1);

        // Stores the maximum number of columns we can keep
        int best = 1;

        // Try every column as the ending column
        for (int j = 0; j < cols; j++) {

            // Try to extend sequences ending at previous columns
            for (int i = 0; i < j; i++) {

                boolean valid = true;

                // Check all rows to ensure non-decreasing order
                for (int r = 0; r < rows; r++) {
                    // If any row violates ordering, extension is not allowed
                    if (strs[r].charAt(i) > strs[r].charAt(j)) {
                        valid = false;
                        break;
                    }
                }

                // If column j can follow column i, update DP state
                if (valid) {
                    keep[j] = Math.max(keep[j], keep[i] + 1);
                }
            }

            // Update global maximum sequence length
            best = Math.max(best, keep[j]);
        }

        /*
           Minimum deletions required =
           total columns - maximum columns that can be kept
        */
        return cols - best;
    }
}
