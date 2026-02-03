class Solution {
    public int minDeletionSize(String[] words) {

        // Number of rows (strings)
        int n = words.length;

        // Number of columns (length of each string)
        int m = words[0].length();

        /*
         * dp[c] = length of the longest valid
         * non-decreasing column sequence
         * that ends at column index c
         */
        int[] dp = new int[m];

        // Base case: each column by itself is always valid
        Arrays.fill(dp, 1);

        // Stores maximum number of columns we can keep
        int maxKeep = 1;

        /*
         * Treat each column as the "ending column"
         * and try to extend sequences from previous columns
         */
        for (int curr = 0; curr < m; curr++) {

            // Check all columns before curr
            for (int prev = 0; prev < curr; prev++) {

                boolean canAttach = true;

                /*
                 * Verify ordering constraint:
                 * For every row, characters in column `prev`
                 * must be <= characters in column `curr`
                 */
                for (int row = 0; row < n; row++) {

                    // Violation found → cannot chain prev → curr
                    if (words[row].charAt(prev) > words[row].charAt(curr)) {
                        canAttach = false;
                        break;
                    }
                }

                /*
                 * If curr column can follow prev column,
                 * update longest valid sequence ending at curr
                 */
                if (canAttach) {
                    dp[curr] = Math.max(dp[curr], dp[prev] + 1);
                }
            }

            // Update global maximum sequence length
            maxKeep = Math.max(maxKeep, dp[curr]);
        }

        /*
         * Minimum deletions required =
         * total columns - maximum columns we can keep
         */
        return m - maxKeep;
    }
}
