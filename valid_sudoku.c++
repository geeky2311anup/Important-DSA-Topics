class Solution {
public:

    // 🔹 Function to validate a single 3x3 subgrid
    // startRow and startCol indicate the top-left corner of the box
    bool checkBox(int startRow, int startCol, vector<vector<char>>& board) {
        vector<bool> seen(10, false); // index 1-9 track digits already present

        for (int r = startRow; r < startRow + 3; r++) {
            for (int c = startCol; c < startCol + 3; c++) {

                char ch = board[r][c];

                // ignore empty cells
                if (ch == '.') continue;

                int num = ch - '0'; // convert char → integer

                // if already seen, duplicate exists → invalid Sudoku
                if (seen[num]) {
                    return false;
                }

                // mark digit as seen
                seen[num] = true;
            }
        }

        // no duplicates found in this box
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {

        // 🔹 1. Check each row
        for (int r = 0; r < 9; r++) {

            vector<bool> seen(10, false); // reset for each row

            for (int c = 0; c < 9; c++) {

                char ch = board[r][c];

                if (ch == '.') continue;

                int num = ch - '0';

                // duplicate found in row
                if (seen[num]) {
                    return false;
                }

                seen[num] = true;
            }
        }


        // 🔹 2. Check each column
        for (int c = 0; c < 9; c++) {

            vector<bool> seen(10, false); // reset for each column

            for (int r = 0; r < 9; r++) {

                char ch = board[r][c];

                if (ch == '.') continue;

                int num = ch - '0';

                // duplicate found in column
                if (seen[num]) {
                    return false;
                }

                seen[num] = true;
            }
        }


        // 🔹 3. Check all 3x3 subgrids
        // starting points: (0,0), (0,3), (0,6), (3,0), ...
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {

                // if any box is invalid → whole Sudoku invalid
                if (!checkBox(r, c, board)) {
                    return false;
                }
            }
        }


        // 🔹 If all checks passed → valid Sudoku
        return true;
    }
};
