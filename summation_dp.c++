class Solution {
    public long minimumTotalDistance(List<Integer> robots, int[][] factories) {

        // Step 1: Sort robot positions in ascending order
        // This helps in assigning closest robots first
        Collections.sort(robots);

        // Step 2: Sort factories based on their positions
        // So we process them from left to right
        Arrays.sort(factories, (x, y) -> Integer.compare(x[0], y[0]));

        int n = robots.size();      // number of robots
        int m = factories.length;  // number of factories

        // DP table:
        // cost[i][j] = minimum distance to fix first i robots using first j factories
        long[][] cost = new long[n + 1][m + 1];

        // Step 3: Initialize DP with large values (infinity)
        for (int i = 0; i <= n; i++) {
            Arrays.fill(cost[i], Long.MAX_VALUE / 2);
        }

        // Base Case:
        // If there are 0 robots, total distance is 0 regardless of factories
        for (int j = 0; j <= m; j++) {
            cost[0][j] = 0;
        }

        // Step 4: Process each factory one by one
        for (int j = 1; j <= m; j++) {

            int factoryPos = factories[j - 1][0]; // current factory position
            int capacity = factories[j - 1][1];  // max robots this factory can handle

            // Try to repair i robots using first j factories
            for (int i = 0; i <= n; i++) {

                // Option 1:
                // Skip this factory, carry forward previous result
                cost[i][j] = cost[i][j - 1];

                long totalDistance = 0;

                // Option 2:
                // Assign 'used' robots to this factory (up to its capacity)
                for (int used = 1; used <= capacity && i - used >= 0; used++) {

                    // We assign robots from the end (closest grouping strategy)
                    int robotIndex = i - used;

                    // Add distance of this robot to current factory
                    totalDistance += Math.abs(robots.get(robotIndex) - factoryPos);

                    // Update DP:
                    // previous (i - used robots with j-1 factories) + current cost
                    cost[i][j] = Math.min(
                        cost[i][j],
                        cost[i - used][j - 1] + totalDistance
                    );
                }
            }
        }

        // Final answer:
        // minimum distance to repair all robots using all factories
        return cost[n][m];
    }
}
