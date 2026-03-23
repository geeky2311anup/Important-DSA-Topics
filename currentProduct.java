class Solution {

    private static long dfs(int row, int col, int[][] matrix, long currentProduct) {
        // base case: reached top-left cell
        if (row == 0 && col == 0) {
            return currentProduct * matrix[0][0];
        }

        // if product becomes zero, no need to continue
        if (currentProduct == 0) return 0;

        long fromTop = Long.MIN_VALUE;
        long fromLeft = Long.MIN_VALUE;

        // move up
        if (row > 0) {
            fromTop = dfs(row - 1, col, matrix, currentProduct * matrix[row][col]);
        }

        // move left
        if (col > 0) {
            fromLeft = dfs(row, col - 1, matrix, currentProduct * matrix[row][col]);
        }

        return Math.max(fromTop, fromLeft);
    }

    public int maxProductPath(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        long result = dfs(rows - 1, cols - 1, matrix, 1L);

        if (result < 0) return -1;

        return (int) (result % 1000000007);
    }
}
