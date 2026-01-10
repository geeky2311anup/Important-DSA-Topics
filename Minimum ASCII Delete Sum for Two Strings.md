# 712. Minimum ASCII Delete Sum for Two Strings

## Problem Summary

Given two strings s1 and s2, you are allowed to delete characters from either string.
Each deleted character costs its ASCII value.

Your task is to make both strings equal with the minimum possible total ASCII delete cost.

Only deletion is allowed.
No replacement.
No reordering.
Just pain and math.

---

## Core Idea

Since only deletions are allowed, both strings must eventually become the same subsequence.

We use Dynamic Programming because:
- We compare prefixes of the strings
- Subproblems overlap
- Each decision affects future cost

---

## DP Definition

Let:

dp[i][j] = minimum ASCII delete sum  
to make s1[0..i-1] and s2[0..j-1] equal

Meaning:
- i characters taken from s1
- j characters taken from s2

---

## DP Table Size

If:
- n = length of s1
- m = length of s2

Then the DP table size is:

(n + 1) x (m + 1)

Extra row and column represent empty strings.

---

## Base Cases

### When s1 is empty

To match an empty s1 with s2[0..j-1],
we must delete all characters from s2.

dp[0][j] = ASCII sum of s2[0..j-1]

### When s2 is empty

Same logic.

dp[i][0] = ASCII sum of s1[0..i-1]

---

## Example Base Table (s1 = "sea", s2 = "eat")

      ""    e     a     t
""     0   101   198   314
s    115
e    216
a    313

Each cell accumulates delete cost.

---

## Transition Logic

### Case 1: Characters Match

If s1[i-1] == s2[j-1]:

No deletion needed.
We move diagonally.

dp[i][j] = dp[i-1][j-1]

---

### Case 2: Characters Do Not Match

We have two options:

1. Delete s1[i-1]
   Cost = ASCII(s1[i-1]) + dp[i-1][j]

2. Delete s2[j-1]
   Cost = ASCII(s2[j-1]) + dp[i][j-1]

We choose the minimum.

dp[i][j] = min(
    s1[i-1] + dp[i-1][j],
    s2[j-1] + dp[i][j-1]
)

---

## Final Answer

The minimum ASCII delete sum for the full strings is stored at:

dp[n][m]

---

## Java Implementation

(Indented instead of fenced to avoid breaking the markdown block)

    class Solution {
        public int minimumDeleteSum(String s1, String s2) {
            char[] st1 = s1.toCharArray();
            char[] st2 = s2.toCharArray();

            int n = st1.length;
            int m = st2.length;

            int[][] dp = new int[n + 1][m + 1];

            // Base case: s2 empty
            for (int i = 1; i <= n; i++) {
                dp[i][0] = dp[i - 1][0] + st1[i - 1];
            }

            // Base case: s1 empty
            for (int j = 1; j <= m; j++) {
                dp[0][j] = dp[0][j - 1] + st2[j - 1];
            }

            // Fill DP table
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (st1[i - 1] == st2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = Math.min(
                            st1[i - 1] + dp[i - 1][j],
                            st2[j - 1] + dp[i][j - 1]
                        );
                    }
                }
            }

            return dp[n][m];
        }
    }

---

## Complexity Analysis

Time Complexity: O(n * m)  
Space Complexity: O(n * m)

---

## Final Thought

This problem is not about deleting characters.
It’s about choosing which characters deserve to survive.

DP is just regret minimization with a table.
