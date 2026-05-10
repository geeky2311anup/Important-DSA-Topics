class Solution {

    // Checks whether we can jump from index 'from' to index 'to'
    // A jump is valid if:
    // 1. from < to
    // 2. Difference between values is within target limit
    private boolean canJump(int from, int to, int[] arr, int limit) {
        return from < to && Math.abs(arr[from] - arr[to]) <= limit;
    }

    public int maximumJumps(int[] nums, int target) {

        int size = nums.length;

        // best[i] stores the maximum jumps needed
        // to reach the last index starting from i
        int[] best = new int[size];

        // Initially mark all positions as unreachable
        for (int k = 0; k < size; k++) {
            best[k] = -1;
        }

        // Last index needs 0 jumps to reach itself
        best[size - 1] = 0;

        // Traverse from second last index to first
        for (int i = size - 2; i >= 0; i--) {

            // Stores maximum jumps possible from current index
            int answer = -1;

            // Try jumping to every next index
            for (int j = i + 1; j < size; j++) {

                // Check:
                // 1. Jump is valid
                // 2. Destination index can reach end
                if (canJump(i, j, nums, target) && best[j] != -1) {

                    // Update maximum jumps
                    answer = Math.max(answer, best[j] + 1);
                }
            }

            // Save result for current index
            best[i] = answer;
        }

        // Maximum jumps possible from index 0
        return best[0];
    }
}
