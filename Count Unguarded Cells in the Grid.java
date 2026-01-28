// LeetCode: Count Unguarded Cells in the Grid
class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {

        // Grid representation using characters:
        // 'n' → empty & not guarded
        // 'g' → guard
        // 'w' → wall
        // 'l' → guarded horizontally (from left/right)
        // 'u' → guarded vertically (from up)
        // 'd' → guarded vertically (from down)
        // 'a' → guarded from multiple directions
        char[][] arr = new char[m][n];

        // Step 1: Initialize the grid with unguarded cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 'n';
            }
        }

        // Step 2: Place guards on the grid
        for (int i = 0; i < guards.length; i++) {
            arr[guards[i][0]][guards[i][1]] = 'g';
        }

        // Step 3: Place walls on the grid
        for (int i = 0; i < walls.length; i++) {
            arr[walls[i][0]][walls[i][1]] = 'w';
        }

        // Step 4: Traverse the grid
        // Whenever a guard is found, extend its line of sight
        // in all four directions until a wall or another guard blocks it
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If current cell contains a guard
                if (arr[i][j] == 'g') {

                    // Look LEFT
                    for (int k = j - 1; k >= 0; k--) {
                        if (arr[i][k] == 'n') {
                            arr[i][k] = 'l'; // guarded horizontally
                        }
                        // Stop vision if obstacle or already guarded horizontally
                        else if (arr[i][k] == 'g' || arr[i][k] == 'w'
                              || arr[i][k] == 'l' || arr[i][k] == 'r'
                              || arr[i][k] == 'a') {
                            break;
                        }
                        // Cell already guarded vertically → mark as guarded from multiple directions
                        else if (arr[i][k] == 'u' || arr[i][k] == 'd') {
                            arr[i][k] = 'a';
                        }
                    }

                    // Look RIGHT
                    for (int k = j + 1; k < n; k++) {
                        if (arr[i][k] == 'n') {
                            arr[i][k] = 'l';
                        }
                        else if (arr[i][k] == 'g' || arr[i][k] == 'w'
                              || arr[i][k] == 'l' || arr[i][k] == 'r'
                              || arr[i][k] == 'a') {
                            break;
                        }
                        else if (arr[i][k] == 'u' || arr[i][k] == 'd') {
                            arr[i][k] = 'a';
                        }
                    }

                    // Look UP
                    for (int k = i - 1; k >= 0; k--) {
                        if (arr[k][j] == 'n') {
                            arr[k][j] = 'u'; // guarded vertically
                        }
                        else if (arr[k][j] == 'g' || arr[k][j] == 'w'
                              || arr[k][j] == 'u' || arr[k][j] == 'd'
                              || arr[k][j] == 'a') {
                            break;
                        }
                        else if (arr[k][j] == 'l' || arr[k][j] == 'r') {
                            arr[k][j] = 'a';
                        }
                    }

                    // Look DOWN
                    for (int k = i + 1; k < m; k++) {
                        if (arr[k][j] == 'n') {
                            arr[k][j] = 'd';
                        }
                        else if (arr[k][j] == 'g' || arr[k][j] == 'w'
                              || arr[k][j] == 'u' || arr[k][j] == 'd'
                              || arr[k][j] == 'a') {
                            break;
                        }
                        else if (arr[k][j] == 'l' || arr[k][j] == 'r') {
                            arr[k][j] = 'a';
                        }
                    }
                }
            }
        }

        // Step 5: Count cells that remain unguarded
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'n') {
                    count++;
                }
            }
        }

        return count;
    }
}
