
---

## 🎯 Intuition — what you want to do  
> We are given `n` points. The goal is to count a certain quadrilateral configuration formed by pairs of segments that are parallel and lie on different supporting lines (the code follows a known trick that counts ordered segment-pairs grouped by direction and offset, then adjusts for double-counting of opposite-direction segments).  
>
> Instead of trying to enumerate 4-tuples of points directly (which is messy and slow), the idea is to treat **every unordered pair of points** as a segment, group segments by their direction (slope) and by an invariant offset (line identifier), and then count how many pairs of segments share direction but lie on different parallel lines. After a correction using the raw (not-normalized) vector grouping we obtain the final count.

---

## 🎯 What you want to do (high-level goal / why)  
> - For every unordered pair of points we create a segment vector `(dx, dy)` and normalize it to a canonical direction `(sx, sy)` (reduced by gcd and sign-fixed).  
> - For that direction, compute an **offset** value `offset = sx*y - sy*x` which is constant for all points on the same line with direction `(sx,sy)`. That groups segments by which parallel line they lie on.  
> - For each direction group, we want to count ordered pairs of segments that live on **different** offsets (i.e., two distinct parallel lines). Summing over directions gives `a`.  
> - But segments made from swapped endpoints (raw `(dx,dy)` vs normalized `(sx,sy)`) produce additional structure; we compute a similar sum `b` using the raw, non-reduced vector grouping and then combine `a - b/2` to correct for overcounting (follows the combinatorial derivation behind the approach).  
>
> This avoids enumerating 4-point combinations directly and reduces the problem to counting frequencies and combining them algebraically.

---

## 🧠 Why this works  
> - Two segments that are parallel and lie on different parallel lines produce one kind of contribution toward the final shape we count (think: edges of a trapezoid/parallelogram-like structure depending on the target). Counting pairwise combinations of segments on different offsets inside the same direction group enumerates many required quadrilaterals.  
> - The `offset = sx*y - sy*x` is invariant for translating along the direction `(sx,sy)`, so it identifies the supporting parallel line uniquely for the normalized direction.  
> - `countPairs(map)` computes \(\sum_{i<j} c_i \cdot c_j\) (implemented as an \(O(m)\) single-pass using prefix-sum trick) which is exactly the total of ordered/unordered segment-pair products inside a direction group.  
> - The second map `byRawVector` (using raw `dx,dy`) captures certain ordered-pair duplications that must be subtracted (half of them) to get the correct final combinatorial count; hence `result = a - b/2`. This algebraic correction comes from the decomposition of how many times a configuration is counted when using normalized vs raw vectors.

---

## 🔧 Approach (matching the implementation)

1. **Enumerate all segments**: loop `i < j` and compute `dx = x2-x1`, `dy = y2-y1`.  
2. **Canonicalize direction**:
   - Flip signs so `(dx,dy)` is canonical (dx>0 or dx==0 and dy>0).  
   - Reduce by `g = gcd(|dx|, |dy|)` to get `(sx,sy)` — the reduced direction vector.  
3. **Compute offset** for a supporting line using the reduced vector:  
   - `offset = sx*y1 - sy*x1` (this is constant for any point on that line).  
4. **Group counts**:
   - `byDirection[ (sx,sy) ][ offset ]++`  
   - `byRawVector[ (dx,dy) ][ offset ]++`  
   Both maps count how many segments (unordered point-pairs) lie on the same directed line (normalized or raw).  
5. **Aggregate pair contributions**:
   - For each inner map (a specific direction), `countPairs` computes sum of `ci * cj` over all pairs of different offsets — i.e., the number of ordered (or combinatorial) segment pairs with that direction on different parallel lines. Sum these to get `a` (for normalized directions) and `b` (for raw vectors).  
6. **Combine results**:
   - `result = a - b/2` applies the algebraic correction (the derivation depends on how raw vs normalized counts double-count certain arrangements).  
7. Return `result` as integer.

---

## 🔍 What each part contributes (detailed)

### Pair enumeration loop
> Produces every unordered segment exactly once and computes both its normalized direction `dirKey` and raw vector `rawKey`, plus the offset for the supporting line.

### `packPair(int a, int b)`
> Packs two 32-bit ints into a single 64-bit key so we can use a primitive long as a map key for direction or vector. Keeps maps efficient and avoids creating small pair objects.

### `gcd(...)` and normalization
> Ensures all parallel segments with proportional direction vectors collapse to the same `(sx,sy)` key, so different-length segments on the same slope group together.

### `offset = sx*y - sy*x`
> Line identifier invariant under translation along direction — essential to group segments by which parallel line they belong to.

### `byDirection` and `byRawVector`
> Two different groupings used to compute two frequency-aggregation statistics (`a` and `b`) needed for the final corrected count.

### `countPairs(map)`
> For each direction group (an inner map of offset → count), it computes:
> \[
> \sum_{i<j} cnt_i \times cnt_j
> \]
> implemented via a single-pass formula: accumulate total `sum`, then for each `cnt` subtract it from `sum` and add `cnt * sum` to `totalPairs`. This runs in time linear in the size of the inner map.

### Final combination `a - b/2`
> Algebraic correction to remove double-counts produced by the raw-vector grouping vs normalized-direction grouping. The division by two is integer division of an even number `b` (the logic ensures `b` is even in valid geometrical inputs).

---

## 🧪 Dry Run (small conceptual example)

Points forming a rectangle:
(0,0), (2,0), (2,1), (0,1)

arduino
Copy code
Segments (unordered pairs) include horizontal segments on y=0 and y=1, vertical segments on x=0 and x=2, and diagonals.  
- For horizontal normalized direction `(1,0)`, offsets identify y=0 and y=1 lines; counts per offset might be `cnt_y0 = 1`, `cnt_y1 = 1` (the horizontal segments for those lines). `countPairs` over that direction yields `1*1 = 1` pair (top-bottom horizontal pair).  
- Similarly vertical direction and other vector groups contribute; after computing `a` and `b` and combining, you obtain the correct number of target quadrilateral configurations (the code’s algebraic correction handles overlaps and double counts).

> Note: this dry run is conceptual — the full per-segment list and intermediate counts can be enumerated to verify `a` and `b` on this simple case.

---

## 📊 Complexity

> - **Time Complexity:** `O(n^2)` to enumerate all `n(n-1)/2` unordered point-pairs and do map updates. The subsequent aggregation runs in linear time in the number of distinct direction keys and offsets (≤ number of segments).  
> - **Space Complexity:** `O(n^2)` in worst case to store counts for many different direction/offset pairs (but typically less when many segments share directions or offsets).

---

## 💻 Code

```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int countTrapezoids(int[][] points) {
        int n = points.length;
        if (n < 4) return 0;

        // Map for direction-normalized lines: directionKey -> (offsetKey -> count)
        Map<Long, Map<Long, Integer>> byDirection = new HashMap<>();
        // Map that preserves raw dx/dy pair (for a slightly different grouping used later)
        Map<Long, Map<Long, Integer>> byRawVector = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                // Normalize sign so direction is canonical (dx > 0 or dx==0 and dy>0)
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                int g = gcd(Math.abs(dx), Math.abs(dy));
                int sx = dx / g;
                int sy = dy / g;

                // compute a line offset parameter that is invariant under translation along the direction:
                // using (sx * y - sy * x) (fits in long if coordinates are moderate)
                long offset = (long) sx * y1 - (long) sy * x1;

                long dirKey = packPair(sx, sy);
                long rawKey = packPair(dx, dy);

                // increment count in direction-normalized map
                byDirection.computeIfAbsent(dirKey, k -> new HashMap<>())
                           .merge(offset, 1, Integer::sum);

                // increment count in raw-vector map
                byRawVector.computeIfAbsent(rawKey, k -> new HashMap<>())
                           .merge(offset, 1, Integer::sum);
            }
        }

        long a = countPairs(byDirection);
        long b = countPairs(byRawVector);

        // follow original formula: calculate(dir) - calculate(raw)/2
        long result = a - b / 2;
        return (int) result;
    }

    // Count ordered pairs of segments that lie on the same direction-group but have different offsets.
    // For each inner map: if counts are c1, c2, ..., then sum_{i<j} ci * cj. The implementation computes this efficiently.
    private long countPairs(Map<Long, Map<Long, Integer>> map) {
        long totalPairs = 0L;

        for (Map<Long, Integer> inner : map.values()) {
            long sum = 0L;
            for (int cnt : inner.values()) sum += cnt;

            // accumulate pair contributions: for each group element count, pairs formed with remaining elements
            for (int cnt : inner.values()) {
                sum -= cnt;
                totalPairs += (long) cnt * sum;
            }
        }

        return totalPairs;
    }

    // gcd that handles zeros safely
    private int gcd(int a, int b) {
        if (a == 0) return Math.abs(b);
        if (b == 0) return Math.abs(a);
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return Math.abs(a);
    }

    // pack two 32-bit signed ints into a single 64-bit long key
    private long packPair(int a, int b) {
        return ((long) a << 32) ^ (b & 0xffffffffL);
    }
}
