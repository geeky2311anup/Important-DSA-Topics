//problem link-> https://leetcode.com/problems/set-intersection-size-at-least-two/submissions/1835331740/?envType=daily-question&envId=2025-11-20

class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        // Sort by ending point; if tie, sort by starting point in descending order
        Arrays.sort(intervals, (x, y) -> {
            if (x[1] == y[1]) return y[0] - x[0];
            return x[1] - y[1];
        });

        List<Integer> picked = new ArrayList<>();
        int result = 0;

        for (int[] inter : intervals) {
            int left = inter[0];
            int right = inter[1];
            int hits = 0;

            // Count how many chosen numbers fall inside this interval
            for (int i = picked.size() - 1; i >= 0 && hits < 2; i--) {
                int val = picked.get(i);
                if (val >= left && val <= right) {
                    hits++;
                }
            }

            // If nothing intersects, choose two new points
            if (hits == 0) {
                picked.add(right - 1);
                picked.add(right);
                result += 2;
            }
            // If only one intersects, choose one more
            else if (hits == 1) {
                picked.add(right);
                result++;
            }
        }

        return result;
    }
}






