

// We are given an array and need to process each sliding window of size k.
// For every window, we must find the sum of the top x most frequent numbers, where each number contributes frequency × value to the total.

// Essentially:

// Maintain frequencies of numbers in the current window.

// Pick the x numbers with the highest frequency (and highest value if frequencies tie).

// Compute their total contribution to the sum.

// 🚀 Approach

// Sliding Window:
// Use two pointers (l and r) to maintain a window of size k.
// As we move the window:

// Add nums[r] to the frequency map.

// Remove nums[l] when the window exceeds size k.

// Frequency Tracking:
// Maintain a HashMap<Integer, Integer> to store frequencies of current window elements.

// Compute Top x Sum:

// Convert frequency map into a max-heap (priority queue) sorted by:

// Higher frequency first

// If equal frequency → higher value first

// Extract top x elements from the heap, summing freq × value for each.

// Store Results:
// For each valid window of size k, compute its x-sum using the heap helper function and store it in the answer array.

// ⏱️ Complexity
// Type	Complexity
// Time	O(n × x log n) in worst case (heap rebuild for each window)
// Space	O(k) for frequency map and heap
// 💻 Code
import java.util.*;

class Solution {
    private int topXSum(Map<Integer, Integer> freq, int x) {
        // Max-heap by (frequency desc, value desc)
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return b[0] - a[0];
            return b[1] - a[1];
        });
        for (Map.Entry<Integer, Integer> e : freq.entrySet()) {
            pq.add(new int[]{e.getValue(), e.getKey()});
        }

        long sum = 0;
        int take = x;
        while (take-- > 0 && !pq.isEmpty()) {
            int[] cur = pq.poll();
            sum += (long) cur[0] * cur[1];
        }
        return (int) sum;
    }

    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        if (k > n) return new int[0];
        int outLen = n - k + 1;
        int[] ans = new int[outLen];

        Map<Integer, Integer> cnt = new HashMap<>();
        int l = 0, idx = 0;

        for (int r = 0; r < n; r++) {
            cnt.put(nums[r], cnt.getOrDefault(nums[r], 0) + 1);

            while (r - l + 1 > k) {
                int v = nums[l++];
                int c = cnt.get(v) - 1;
                if (c == 0) cnt.remove(v);
                else cnt.put(v, c);
            }

            if (r - l + 1 == k) {
                ans[idx++] = topXSum(cnt, x);
            }
        }
        return ans;
    }
}

// 🧩 Example

// Input:
// nums = [1,2,2,3,3,3], k = 3, x = 2
// Sliding windows:

// [1,2,2] → {2:2, 1:1} → top 2 → (2×2 + 1×1) = 5

// [2,2,3] → {2:2, 3:1} → top 2 → (2×2 + 1×3) = 7

// [2,3,3] → {2:1, 3:2} → top 2 → (1×2 + 2×3) = 8

// [3,3,3] → {3:3} → top 1 = 9

Output: [5,7,8,9]
