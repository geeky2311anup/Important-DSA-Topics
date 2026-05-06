class Solution {
    public char[][] rotateTheBox(char[][] box) {

        int rows = box.length;
        int cols = box[0].length;

        // Apply gravity toward the right
        for (int r = 0; r < rows; r++) {

            int writePos = cols - 1;

            for (int c = cols - 1; c >= 0; c--) {

                if (box[r][c] == '*') {
                    writePos = c - 1;
                }

                else if (box[r][c] == '#') {

                    box[r][c] = '.';
                    box[r][writePos] = '#';
                    writePos--;
                }
            }
        }

        // Rotate 90 degrees clockwise
        char[][] rotated = new char[cols][rows];

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                rotated[c][rows - 1 - r] = box[r][c];
            }
        }

        return rotated;
    }
}

