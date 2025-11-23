class Solution {
    public int maxSumDivThree(int[] nums) {
        int total = 0;

        // best[r] = smallest number with value % 3 == r
        // second[r] = second smallest number with value % 3 == r
        final int INF = Integer.MAX_VALUE;
        int[] best = {INF, INF, INF};
        int[] second = {INF, INF, INF};

        for (int x : nums) {
            total += x;
            int r = x % 3;

            // update the two smallest values for this remainder
            if (x < best[r]) {
                second[r] = best[r];
                best[r] = x;
            } else if (x < second[r]) {
                second[r] = x;
            }
        }

        // If sum already divisible by 3:
        if (total % 3 == 0) return total;

        int rem = total % 3;
        int ans = 0;

        if (rem == 1) {
            int option1 = (best[1] < INF) ? total - best[1] : 0;
            int option2 = (best[2] < INF && second[2] < INF)
                            ? total - best[2] - second[2]
                            : 0;
            ans = Math.max(option1, option2);
        } else { // rem == 2
            int option1 = (best[2] < INF) ? total - best[2] : 0;
            int option2 = (best[1] < INF && second[1] < INF)
                            ? total - best[1] - second[1]
                            : 0;
            ans = Math.max(option1, option2);
        }

        return ans;
    }
}
