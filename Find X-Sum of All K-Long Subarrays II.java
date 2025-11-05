import java.util.*;

class Solution {
    // freq of each value
    private Map<Integer, Integer> cnt;

    // buckets: freq -> set of values (ascending). top = picked set, pool = the rest
    private TreeMap<Integer, TreeSet<Integer>> topBuckets, poolBuckets;

    private long pickedSum; // sum of f*v over "top" set
    private int picked;     // how many entries in "top"

    private static void add(TreeMap<Integer, TreeSet<Integer>> m, int f, int v) {
        m.computeIfAbsent(f, k -> new TreeSet<>()).add(v);
    }
    private static void remove(TreeMap<Integer, TreeSet<Integer>> m, int f, int v) {
        TreeSet<Integer> s = m.get(f);
        if (s == null) return;
        s.remove(v);
        if (s.isEmpty()) m.remove(f);
    }

    // best in pool: highest freq, then highest value
    private static int[] best(TreeMap<Integer, TreeSet<Integer>> m) {
        if (m.isEmpty()) return null;
        int f = m.lastKey();
        int v = m.get(f).last();
        return new int[]{f, v};
    }

    // worst in top: lowest freq, then lowest value
    private static int[] worst(TreeMap<Integer, TreeSet<Integer>> m) {
        if (m.isEmpty()) return null;
        int f = m.firstKey();
        int v = m.get(f).first();
        return new int[]{f, v};
    }

    private void movePoolToTop() {
        int[] b = best(poolBuckets);
        if (b == null) return;
        remove(poolBuckets, b[0], b[1]);
        add(topBuckets, b[0], b[1]);
        picked++;
        pickedSum += 1L * b[0] * b[1];
    }

    private void moveTopToPool() {
        int[] w = worst(topBuckets);
        if (w == null) return;
        remove(topBuckets, w[0], w[1]);
        add(poolBuckets, w[0], w[1]);
        picked--;
        pickedSum -= 1L * w[0] * w[1];
    }

    private void rebalance(int x) {
        while (picked > x) moveTopToPool();
        while (picked < x && !poolBuckets.isEmpty()) movePoolToTop();
    }

    private boolean inTop(int f, int v) {
        TreeSet<Integer> s = topBuckets.get(f);
        return s != null && s.contains(v);
    }

    private void addVal(int v, int x) {
        int f = cnt.getOrDefault(v, 0);

        // remove old placement if existed
        if (f > 0) {
            if (inTop(f, v)) {
                remove(topBuckets, f, v);
                picked--;
                pickedSum -= 1L * f * v;
            } else {
                remove(poolBuckets, f, v);
            }
        }

        f++;
        cnt.put(v, f);

        // new freq enters "top" for now; we'll rebalance after
        add(topBuckets, f, v);
        picked++;
        pickedSum += 1L * f * v;

        rebalance(x);
    }

    private void removeVal(int v, int x) {
        Integer cur = cnt.get(v);
        if (cur == null || cur == 0) return;
        int f = cur;

        // remove from current location
        if (inTop(f, v)) {
            remove(topBuckets, f, v);
            picked--;
            pickedSum -= 1L * f * v;
        } else {
            remove(poolBuckets, f, v);
        }

        f--;
        if (f == 0) {
            cnt.remove(v);
        } else {
            // demoted version goes to pool; rebalance may pull it back up
            add(poolBuckets, f, v);
            cnt.put(v, f);
        }

        rebalance(x);
    }

    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        long[] res = new long[n - k + 1];

        cnt = new HashMap<>();
        topBuckets = new TreeMap<>();
        poolBuckets = new TreeMap<>();
        pickedSum = 0L;
        picked = 0;

        for (int i = 0; i < k; i++) addVal(nums[i], x);
        res[0] = pickedSum;

        for (int l = 1, r = k; r < n; l++, r++) {
            removeVal(nums[l - 1], x);
            addVal(nums[r], x);
            res[l] = pickedSum;
        }
        return res;
    }
}
