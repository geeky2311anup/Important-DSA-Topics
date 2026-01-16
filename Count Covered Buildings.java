class Solution {

    public int countCoveredBuildings(int n, int[][] buildings) {

        // Map to store all Y-coordinates grouped by the same X (same column)
        // Example: x = 3 → [1, 4, 7]
        Map<Integer, List<Integer>> colMap = new HashMap<>();

        // Map to store all X-coordinates grouped by the same Y (same row)
        // Example: y = 5 → [2, 6, 9]
        Map<Integer, List<Integer>> rowMap = new HashMap<>();

        // Step 1: Group all building coordinates by column (x) and row (y)
        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            // Add y into the list of values for this x-column
            colMap.computeIfAbsent(x, v -> new ArrayList<>()).add(y);

            // Add x into the list of values for this y-row
            rowMap.computeIfAbsent(y, v -> new ArrayList<>()).add(x);
        }

        // Step 2: Sort all Y-values in each column
        // This allows easy access to lowest and highest buildings in that column
        for (List<Integer> ys : colMap.values()) {
            Collections.sort(ys);
        }

        // Step 3: Sort all X-values in each row
        // This allows easy access to leftmost and rightmost buildings in that row
        for (List<Integer> xs : rowMap.values()) {
            Collections.sort(xs);
        }

        int covered = 0;

        // Step 4: Check each building whether it is "covered"
        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            // Get all buildings in the same column (same x)
            List<Integer> ys = colMap.get(x);

            // Get all buildings in the same row (same y)
            List<Integer> xs = rowMap.get(y);

            /*
               A building is considered covered if:

               - There exists a building to the LEFT and RIGHT in the same row
               - There exists a building BELOW and ABOVE in the same column

               After sorting:
               xs.get(0)             → leftmost building in row
               xs.get(xs.size()-1)   → rightmost building in row
               ys.get(0)             → bottommost building in column
               ys.get(ys.size()-1)   → topmost building in column
            */

            boolean hasLeft  = xs.get(0) < x;
            boolean hasRight = xs.get(xs.size() - 1) > x;
            boolean hasDown  = ys.get(0) < y;
            boolean hasUp    = ys.get(ys.size() - 1) > y;

            // If all four directions have at least one building,
            // then current building is fully surrounded
            if (hasLeft && hasRight && hasDown && hasUp) {
                covered++;
            }
        }

        // Step 5: Return total covered buildings count
        return covered;
    }
}

