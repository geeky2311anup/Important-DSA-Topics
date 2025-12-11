class Solution {

    public int countCoveredBuildings(int n, int[][] buildings) {

        // Map x → all y's on that column
        Map<Integer, List<Integer>> colMap = new HashMap<>();
        // Map y → all x's on that row
        Map<Integer, List<Integer>> rowMap = new HashMap<>();

        // Group all points by x and by y
        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            colMap.computeIfAbsent(x, v -> new ArrayList<>()).add(y);
            rowMap.computeIfAbsent(y, v -> new ArrayList<>()).add(x);
        }

        // Sort each column's y-coordinates
        for (List<Integer> ys : colMap.values()) {
            Collections.sort(ys);
        }

        // Sort each row's x-coordinates
        for (List<Integer> xs : rowMap.values()) {
            Collections.sort(xs);
        }

        int covered = 0;

        // Check coverage for each building
        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            List<Integer> ys = colMap.get(x); // same x, all y-values
            List<Integer> xs = rowMap.get(y); // same y, all x-values

            // A building is covered if:
            // - In its row, something lies to the left AND to the right
            // - In its column, something lies below AND above
            boolean hasLeft  = xs.get(0) < x;
            boolean hasRight = xs.get(xs.size() - 1) > x;
            boolean hasDown  = ys.get(0) < y;
            boolean hasUp    = ys.get(ys.size() - 1) > y;

            if (hasLeft && hasRight && hasDown && hasUp) {
                covered++;
            }
        }

        return covered;
    }
}
