# Maximum Dot Product of Two Subsequences (LeetCode)

## Problem Overview

Given two integer arrays `nums1` and `nums2`, the task is to find the **maximum dot product** of **non-empty subsequences** from both arrays.

A dot product of two subsequences of equal length is calculated as:

sum(nums1[i] * nums2[i]) for all valid i

Key constraints:
- Subsequences must be **non-empty**
- Order must be preserved
- Negative values are allowed

---

## Approach: Dynamic Programming

We use **2D Dynamic Programming** where:

`dp[i][j]` represents the **maximum dot product** using:
- elements from `nums1[0...i]`
- elements from `nums2[0...j]`

This allows us to decide at every step whether to:
- start a new subsequence
- extend an existing one
- or skip elements

---

## DP Initialization

- `dp[0][0]` is simply the product of the first elements.
- First row and first column are initialized to ensure:
  - subsequences are **non-empty**
  - maximum product is carried forward

---

## DP Transition Logic

For each `(i, j)`:

We consider:
1. Taking only the current pair  
2. Extending a previous subsequence  
3. Skipping elements from either array  

Formula logic:
- Take current product alone
- Extend previous diagonal value
- Carry forward best from top or left

---

## Java Code Implementation

```java
class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        
        int[][] dp = new int[n][m];
        
        // Base case
        dp[0][0] = nums1[0] * nums2[0];
        
        // Initialize first row
        for (int j = 1; j < m; j++) {
            dp[0][j] = Math.max(dp[0][j - 1], nums1[0] * nums2[j]);
        }
        
        // Initialize first column
        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], nums1[i] * nums2[0]);
        }
        
        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int product = nums1[i] * nums2[j];
                
                int takeBoth = Math.max(dp[i - 1][j - 1], dp[i - 1][j - 1] + product);
                takeBoth = Math.max(takeBoth, product);
                
                dp[i][j] = Math.max(
                    takeBoth,
                    Math.max(dp[i - 1][j], dp[i][j - 1])
                );
            }
        }
        
        return dp[n - 1][m - 1];
    }
}
