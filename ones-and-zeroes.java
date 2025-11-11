/*
 * LeetCode Problem:
 * https://leetcode.com/problems/ones-and-zeroes/?envType=daily-question&envId=2025-11-11
 *
 * Problem Summary:
 * ----------------
 * You are given an array of binary strings `strs` and two integers `m` and `n`.
 * Each string can be included in a subset only if the total number of 0s does not exceed `m`
 * and the total number of 1s does not exceed `n`.
 * 
 * The goal is to find the **maximum number of strings** that can be formed under these limits.
 *
 * Approach (3D Dynamic Programming with Recursion + Memoization):
 * ---------------------------------------------------------------
 * - Each string consumes a certain number of 0s and 1s.
 * - We need to decide, for every string:
 *      → Include it (if we have enough zeros and ones left)
 *      → Or skip it
 * - This forms an optimal substructure — ideal for recursion + memoization.
 *
 * Key Idea:
 * ----------
 * - Preprocess each string to count how many '0's and '1's it contains.
 * - Use a recursive function `dfs(index, zerosLeft, onesLeft)`:
 *     → It returns the maximum number of strings we can include starting from index `index`
 *       with `zerosLeft` zeros and `onesLeft` ones remaining.
 *
 * Transition:
 * ------------
 * - If we can include the current string (enough zeros and ones available):
 *       take = 1 + dfs(nextIndex, zerosLeft - zeros[i], onesLeft - ones[i])
 * - Otherwise, we skip the current string:
 *       skip = dfs(nextIndex, zerosLeft, onesLeft)
 * - We store the maximum of these two in the DP table.
 *
 * DP State Definition:
 * --------------------
 * dp[i][j][k] → Maximum number of strings that can be formed
 *               starting from index i, with j zeros and k ones remaining.
 *
 * Base Case:
 * ----------
 * - When `index == strs.length`, we have no strings left → return 0.
 *
 * Complexity:
 * ------------
 * - Time Complexity: O(len * m * n)
 *   (each state is computed once)
 * - Space Complexity: O(len * m * n)
 *   (for the DP memoization table)
 *
 * Example:
 * --------
 * Input:
 * strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 *
 * Output:
 * 4
 *
 * Explanation:
 * We can form 4 strings: "10", "0001", "1", and "0"
 * using at most 5 zeros and 3 ones.
 */

class Solution {
    int[] zeros;
    int[] ones;

    public int findMaxForm(String[] strs, int maxZeros, int maxOnes) {
        int n = strs.length;
        zeros = new int[n];
        ones = new int[n];

        // Step 1: Precompute counts of zeros and ones for each string
        for (int i = 0; i < n; i++) {
            String s = strs[i];
            int zeroCount = 0;
            for (char ch : s.toCharArray()) {
                if (ch == '0') zeroCount++;
            }
            zeros[i] = zeroCount;
            ones[i] = s.length() - zeroCount;
        }

        // Step 2: Initialize DP array
        int[][][] dp = new int[n][maxZeros + 1][maxOnes + 1];

        // Step 3: Run recursive DP helper
        return dfs(0, maxZeros, maxOnes, dp);
    }

    private int dfs(int idx, int zerosLeft, int onesLeft, int[][][] dp) {
        // Base case
        if (idx == zeros.length) return 0;

        // Return already computed value
        if (dp[idx][zerosLeft][onesLeft] != 0)
            return dp[idx][zerosLeft][onesLeft];

        int take = Integer.MIN_VALUE;

        int newZeros = zerosLeft - zeros[idx];
        int newOnes = onesLeft - ones[idx];

        // Include current string if possible
        if (newZeros >= 0 && newOnes >= 0) {
            take = 1 + dfs(idx + 1, newZeros, newOnes, dp);
        }

        // Skip current string
        int skip = dfs(idx + 1, zerosLeft, onesLeft, dp);

        // Store and return result
        return dp[idx][zerosLeft]()
