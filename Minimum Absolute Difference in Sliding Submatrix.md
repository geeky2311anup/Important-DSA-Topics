int[][] result = new int[rows - k + 1][cols - k + 1];

// Iterate over each possible starting row of the k x k window
for (int top = 0; top <= rows - k; top++) {

    // TreeMap to store frequency of elements in current window (keeps keys sorted)
    TreeMap<Integer, Integer> freq = new TreeMap<>();

    // Build the initial k x k window for the first column (left = 0)
    for (int r = top; r < top + k; r++) {
        for (int c = 0; c < k; c++) {
            freq.put(matrix[r][c], freq.getOrDefault(matrix[r][c], 0) + 1);
        }
    }

    // Slide the window horizontally across columns
    for (int left = 0; left <= cols - k; left++) {

        // Compute minimum absolute difference between any two distinct values
        if (freq.size() <= 1) {
            // If only one unique value, difference is 0
            result[top][left] = 0;
        } else {
            int minDiff = Integer.MAX_VALUE;
            Integer prev = null;

            // Since TreeMap is sorted, check adjacent keys for minimum difference
            for (int val : freq.keySet()) {
                if (prev != null) {
                    minDiff = Math.min(minDiff, val - prev);
                }
                prev = val;
            }

            result[top][left] = minDiff;
        }

        // Slide the window one column to the right
        if (left < cols - k) {
            for (int r = top; r < top + k; r++) {

                int removeVal = matrix[r][left];       // element leaving window
                int addVal = matrix[r][left + k];      // element entering window

                // Decrease frequency of removed element
                freq.put(removeVal, freq.get(removeVal) - 1);
                if (freq.get(removeVal) == 0) {
                    freq.remove(removeVal); // remove key if count becomes 0
                }

                // Increase frequency of new element
                freq.put(addVal, freq.getOrDefault(addVal, 0) + 1);
            }
        }
    }
}

return result;
