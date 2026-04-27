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

   import java.util.*;

class Solution {
    // PIPE_MAP defines the relative movements [row_offset, col_offset] allowed for each pipe type.
    // Index matches the pipe type (1-6).
    private final int[][][] PIPE_MAP = {
        {}, // Placeholder for type 0
        {{0, -1}, {0, 1}},  // Type 1: Horizontal (Left, Right)
        {{-1, 0}, {1, 0}},  // Type 2: Vertical (Up, Down)
        {{0, -1}, {1, 0}},  // Type 3: Curve (Left, Down)
        {{0, 1}, {1, 0}},   // Type 4: Curve (Right, Down)
        {{0, -1}, {-1, 0}}, // Type 5: Curve (Left, Up)
        {{0, 1}, {-1, 0}}    // Type 6: Curve (Right, Up)
    };

    public boolean hasValidPath(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();

        // Start BFS from the top-left corner
        queue.offer(new int[]{0, 0});
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int r = cell[0], c = cell[1];

            // Target reached successfully
            if (r == m - 1 && c == n - 1) return true;

            int pipeType = grid[r][c];
            // Iterate through both directions allowed by the current pipe type
            for (int[] offset : PIPE_MAP[pipeType]) {
                int nextR = r + offset[0];
                int nextC = c + offset[1];

                // 1. Check if the neighbor is within grid boundaries
                // 2. Check if the neighbor has already been visited
                if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n && !visited[nextR][nextC]) {
                    // 3. Verify the "Handshake": The neighbor must have an opening 
                    //    pointing back to our current cell.
                    if (canConnect(grid[nextR][nextC], -offset[0], -offset[1])) {
                        visited[nextR][nextC] = true;
                        queue.offer(new int[]{nextR, nextC});
                    }
                }
            }
        }
        return false; // No path found after exploring all reachable cells
    }

    /**
     * Helper method to check if a specific pipe type has an opening in a given direction.
     * @param nextType The integer type of the neighbor pipe.
     * @param backR The row offset required to point back to the previous cell.
     * @param backC The column offset required to point back to the previous cell.
     */
    private boolean canConnect(int nextType, int backR, int backC) {
        for (int[] backDir : PIPE_MAP[nextType]) {
            if (backDir[0] == backR && backDir[1] == backC) return true;
        }
        return false;
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
