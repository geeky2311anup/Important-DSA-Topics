class Solution {
    public int maxSumDivThree(int[] nums) {
        // Sum of all elements
        int total = 0;

        // best[r]   = smallest number with remainder r when divided by 3
        // second[r] = second smallest number with remainder r when divided by 3
        final int INF = Integer.MAX_VALUE;
        int[] best = {INF, INF, INF};
        int[] second = {INF, INF, INF};

        // Iterate through the array to compute total sum
        // and track the two smallest numbers for each remainder class
        for (int x : nums) {
            total += x;
            int r = x % 3;

            // Update smallest and second smallest values for remainder r
            if (x < best[r]) {
                second[r] = best[r];
                best[r] = x;
            } else if (x < second[r]) {
                second[r] = x;
            }
        }

        // If the total sum is already divisible by 3,
        // this is the maximum possible sum
        if (total % 3 == 0) return total;

        int rem = total % 3;
        int ans = 0;

        // If remainder is 1, we need to remove either:
        // 1) the smallest number with remainder 1, or
        // 2) two smallest numbers with remainder 2
        if (rem == 1) {
            int option1 = (best[1] < INF) 
                          ? total - best[1] 
                          : 0;

            int option2 = (best[2] < INF && second[2] < INF)
                          ? total - best[2] - second[2]
                          : 0;

            ans = Math.max(option1, option2);
        } 
        // If remainder is 2, we need to remove either:
        // 1) the smallest number with remainder 2, or
        // 2) two smallest numbers with remainder 1
        else { // rem == 2
            int option1 = (best[2] < INF) 
                          ? total - best[2] 
                          : 0;

            int option2 = (best[1] < INF && second[1] < INF)
                          ? total - best[1] - second[1]
                          : 0;

            ans = Math.max(option1, option2);
        }

        // Return the maximum sum divisible by 3
        return ans;
    }
}
