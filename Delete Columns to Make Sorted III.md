class Solution {
    public int minDeletionSize(String[] words) {

        // Total number of strings (rows)
        int n = words.length;

        // Length of each string (number of columns)
        int m = words[0].length();

        /*
           dp[c] stores the length of the longest
           non-decreasing column sequence that
           ENDS at column c.
        */
        int[] dp = new int[m];

        // Every column alone is always valid
        Arrays.fill(dp, 1);

        // Keeps track of the maximum columns we can keep
        int maxKeep = 1;

        // Treat each column as the ending column
        for (int curr = 0; curr < m; curr++) {

            // Try to extend sequences ending at previous columns
            for (int prev = 0; prev < curr; prev++) {

                boolean canAttach = true;

                // Check all rows to ensure column order is non-decreasing
                for (int row = 0; row < n; row++) {

                    // If any row violates order, this transition is invalid
                    if (words[row].charAt(prev) > words[row].charAt(curr)) {
                        canAttach = false;
                        break;
                    }
                }

                // If column `curr` can follow `prev`, update DP value
                if (canAttach) {
                    dp[curr] = Math.max(dp[curr], dp[prev] + 1);
                }
            }

            // Update the global maximum sequence length
            maxKeep = Math.max(maxKeep, dp[curr]);
        }

        /*
           Minimum deletions needed =
           total columns - maximum columns that can be kept
        */
        return m - maxKeep;
    }
}
