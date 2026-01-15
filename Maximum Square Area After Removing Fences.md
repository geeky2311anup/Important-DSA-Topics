# Maximum Square Area After Removing Fences

## Intuition

To form a square, the height and width must be equal.

The problem reduces to:
- Find all possible vertical distances between horizontal fences.
- Find all possible horizontal distances between vertical fences.
- From these, choose the **largest common distance** that can serve as the side of a square.

If no common distance exists, forming a square is impossible.

---

## Key Observations

- Fences divide the grid into segments.
- Any valid square side length must come from:
  - The distance between two fences, or
  - The distance between a fence and the boundary.
- The order of fences does not matter once distances are computed.
- Using a set helps avoid duplicate distances.

---

## Approach

1. **Generate all possible segment lengths** for horizontal fences:
   - Distance from the top boundary to each fence.
   - Distance from each fence to the bottom boundary.
   - Distance between every pair of fences.

2. **Repeat the same process** for vertical fences.

3. **Compare both sets** to find the maximum length that exists in both.
   - This represents the largest possible square side.

4. **Compute the area** using that side length.
   - Since numbers can be large, apply modulo \(10^9 + 7\).

5. **Return `-1`** if no valid square can be formed.

---

## Why This Works

- Any square must align with fence boundaries.
- Enumerating all possible distances guarantees we don’t miss a valid square.
- Using sets ensures efficient lookups when finding common lengths.

---

## Complexity Analysis

- Let `k` be the number of fences.
- Distance generation takes **O(k²)** time.
- Space complexity is **O(k²)** due to storing all possible distances.

This is acceptable given the problem constraints.

---

## Edge Cases

- No overlapping distances between horizontal and vertical segments.
- Only one fence present.
- Square side length computed as zero (invalid).

All these are handled naturally by the approach.

---

## Final Result

- Returns the **maximum possible square area** modulo \(10^9 + 7\).
- Returns **-1** if forming a square is not possible.
```
class Solution {

    private static final int MOD = 1_000_000_007;

    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        Set<Integer> possibleHeights = getPossibleLengths(m, hFences);
        Set<Integer> possibleWidths = getPossibleLengths(n, vFences);

        long bestSide = 0;

        // Find the largest common side length
        for (int len : possibleHeights) {
            if (possibleWidths.contains(len)) {
                bestSide = Math.max(bestSide, len);
            }
        }

        if (bestSide == 0) return -1;

        return (int) ((bestSide * bestSide) % MOD);
    }

    private Set<Integer> getPossibleLengths(int total, int[] fences) {
        Set<Integer> lengths = new HashSet<>();
        Arrays.sort(fences);

        // Distance from start to end without any fence
        lengths.add(total - 1);

        for (int i = 0; i < fences.length; i++) {
            // From start to current fence
            lengths.add(fences[i] - 1);

            // From current fence to end
            lengths.add(total - fences[i]);

            // Distances between fences
            for (int j = i + 1; j < fences.length; j++) {
                lengths.add(fences[j] - fences[i]);
            }
        }

        return lengths;
    }
}

```
