import java.util.*;

class Solution {

    // Map to store frequency of each number in the current window
    private Map<Integer, Integer> cnt;

    /*
     * Two bucket structures:
     *
     * topBuckets  -> contains the "top X" elements (highest contribution)
     * poolBuckets -> contains the remaining elements
     *
     * Key   = frequency
     * Value = sorted set of values with that frequency
     *
     * TreeMap keeps frequencies sorted
     * TreeSet keeps values sorted
     */
    private TreeMap<Integer, TreeSet<Integer>> topBuckets, poolBuckets;

    // Sum of (frequency * value) for all elements currently in topBuckets
    private long pickedSum;

    // Number of elements currently in topBuckets
    private int picked;

    // Helper: add value to bucket map
    private static void add(TreeMap<Integer, TreeSet<Integer>> m, int f, int v) {
        // Insert value v into frequency bucket f
        m.computeIfAbsent(f, k -> new TreeSet<>()).add(v);
    }

    // Helper: remove value from bucket map
    private static void remove(TreeMap<Integer, TreeSet<Integer>> m, int f, int v) {
        // Get the set for frequency f
        TreeSet<Integer> s = m.get(f);
        if (s == null) return;

        // Remove value
        s.remove(v);

        // If no values left in this frequency bucket, remove the key
        if (s.isEmpty()) m.remove(f);
    }

    /*
     * Get the best candidate from poolBuckets:
     * Highest frequency first,
     * If tie → highest value
     */
    private static int[] best(TreeMap<Integer, TreeSet<Integer>> m) {
        if (m.isEmpty()) return null;

        int f = m.lastKey();             // largest frequency
        int v = m.get(f).last();         // largest value in that frequency
        return new int[]{f, v};
    }

    /*
     * Get the worst element from topBuckets:
     * Lowest frequency first,
     * If tie → lowest value
     */
    private static int[] worst(TreeMap<Integer, TreeSet<Integer>> m) {
        if (m.isEmpty()) return null;

        int f = m.firstKey();            // smallest frequency
        int v = m.get(f).first();        // smallest value in that frequency
        return new int[]{f, v};
    }

    // Move best element from pool → top
    private void movePoolToTop() {
        int[] b = best(poolBuckets);
        if (b == null) return;

        // Remove from pool
        remove(poolBuckets, b[0], b[1]);

        // Add to top
        add(topBuckets, b[0], b[1]);

        // Update counters
        picked++;
        pickedSum += 1L * b[0] * b[1];
    }

    // Move worst element from top → pool
    private void moveTopToPool() {
        int[] w = worst(topBuckets);
        if (w == null) return;

        // Remove from top
        remove(topBuckets, w[0], w[1]);

        // Add to pool
        add(poolBuckets, w[0], w[1]);

        // Update counters
        picked--;
        pickedSum -= 1L * w[0] * w[1];
    }

    /*
     * Ensure exactly x elements are in topBuckets
     */
    private void rebalance(int x) {
        // If too many elements in top, move worst to pool
        while (picked > x) moveTopToPool();

        // If too few elements in top, move best from pool
        while (picked < x && !poolBuckets.isEmpty()) movePoolToTop();
    }

    // Check if a value with frequency f is currently inside topBuckets
    private boolean inTop(int f, int v) {
        TreeSet<Integer> s = topBuckets.get(f);
        return s != null && s.contains(v);
    }

    /*
     * Add a value into sliding window:
     * - Update frequency
     * - Remove old bucket placement
     * - Insert new placement
     * - Rebalance top X elements
     */
    private void addVal(int v, int x) {
        int f = cnt.getOrDefault(v, 0);

        // Remove old frequency placement
        if (f > 0) {
            if (inTop(f, v)) {
                // If element was in top, remove and update sum
                remove(topBuckets, f, v);
                picked--;
                pickedSum -= 1L * f * v;
            } else {
                // Otherwise, remove from pool
                remove(poolBuckets, f, v);
            }
        }

        // Increase frequency
        f++;
        cnt.put(v, f);

        // Temporarily insert into top
        add(topBuckets, f, v);
        picked++;
        pickedSum += 1L * f * v;

        // Fix size of top set
        rebalance(x);
    }

    /*
     * Remove a value from sliding window:
     * - Update frequency
     * - Remove old placement
     * - Insert downgraded frequency into pool
     * - Rebalance top X elements
     */
    private void removeVal(int v, int x) {
        Integer cur = cnt.get(v);
        if (cur == null || cur == 0) return;

        int f = cur;

        // Remove current placement
        if (inTop(f, v)) {
            remove(topBuckets, f, v);
            picked--;
            pickedSum -= 1L * f * v;
        } else {
            remove(poolBuckets, f, v);
        }

        // Decrease frequency
        f--;

        if (f == 0) {
            // Completely remove value
            cnt.remove(v);
        } else {
            // Put downgraded version into pool
            add(poolBuckets, f, v);
            cnt.put(v, f);
        }

        // Fix size of top set
        rebalance(x);
    }

    /*
     * Main function:
     *
     * Sliding window of size k
     * For each window:
     *   - Maintain top X elements by (frequency, value)
     *   - Output sum(freq * value) of top X elements
     */
    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        long[] res = new long[n - k + 1];

        // Initialize structures
        cnt = new HashMap<>();
        topBuckets = new TreeMap<>();
        poolBuckets = new TreeMap<>();
        pickedSum = 0L;
        picked = 0;

        // Build first window
        for (int i = 0; i < k; i++) addVal(nums[i], x);
        res[0] = pickedSum;

        // Slide the window
        for (int l = 1, r = k; r < n; l++, r++) {
            removeVal(nums[l - 1], x);   // remove left element
            addVal(nums[r], x);          // add right element
            res[l] = pickedSum;
        }

        return res;
    }
}
