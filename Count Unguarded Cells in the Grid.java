// LeetCode: Count Unguarded Cells in the Grid
class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {

        // Grid representation
        // n = empty cell
        // g = guard
        // w = wall
        // l, r, u, d = guarded from left/right/up/down
        // a = guarded from multiple directions
        char[][] arr = new char[m][n];

        // Initialize all cells as unguarded
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = 'n';
            }
        }

        // Place guards
        for(int i = 0; i < guards.length; i++){
            arr[guards[i][0]][guards[i][1]] = 'g';
        }

        // Place walls
        for(int i = 0; i < walls.length; i++){
            arr[walls[i][0]][walls[i][1]] = 'w';
        }

        // Traverse grid to simulate guard vision
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                // If a guard is found, spread vision in all 4 directions
                if(arr[i][j] == 'g'){

                    // Look LEFT
                    for(int k = j - 1; k >= 0; k--){
                        if(arr[i][k] == 'n'){
                            arr[i][k] = 'l'; // guarded from left
                        }
                        // Stop if obstacle or already fully guarded
                        else if(arr[i][k] == 'g' || arr[i][k] == 'w'
                             || arr[i][k] == 'l' || arr[i][k] == 'r'
                             || arr[i][k] == 'a'){
                            break;
                        }
                        // Cell already guarded vertically, now guarded from multiple directions
                        else if(arr[i][k] == 'u' || arr[i][k] == 'd'){
                            arr[i][k] = 'a';
                        }
                    }

                    // Look RIGHT
                    for(int k = j + 1; k < n; k++){
                        if(arr[i][k] == 'n'){
                            arr[i][k] = 'l';
                        }
                        else if(arr[i][k] == 'g' || arr[i][k] == 'w'
                             || arr[i][k] == 'l' || arr[i][k] == 'r'
                             || arr[i][k] == 'a'){
                            break;
                        }
                        else if(arr[i][k] == 'u' || arr[i][k] == 'd'){
                            arr[i][k] = 'a';
                        }
                    }

                    // Look UP
                    for(int k = i - 1; k >= 0; k--){
                        if(arr[k][j] == 'n'){
                            arr[k][j] = 'u';
                        }
                        else if(arr[k][j] == 'g' || arr[k][j] == 'w'
                             || arr[k][j] == 'u' || arr[k][j] == 'd'
                             || arr[k][j] == 'a'){
                            break;
                        }
                        else if(arr[k][j] == 'l' || arr[k][j] == 'r'){
                            arr[k][j] = 'a';
                        }
                    }

                    // Look DOWN
                    for(int k = i + 1; k < m; k++){
                        if(arr[k][j] == 'n'){
                            arr[k][j] = 'd';
                        }
                        else if(arr[k][j] == 'g' || arr[k][j] == 'w'
                             || arr[k][j] == 'u' || arr[k][j] == 'd'
                             || arr[k][j] == 'a'){
                            break;
                        }
                        else if(arr[k][j] == 'l' || arr[k][j] == 'r'){
                            arr[k][j] = 'a';
                        }
                    }
                }
            }
        }

        // Count unguarded cells
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 'n'){
                    count++;
                }
            }
        }

        return count;
    }
}
