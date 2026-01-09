# Detect Cycles in 2D Grid (LeetCode)

## Problem Summary

You are given a 2D grid of characters.  
The task is to determine whether the grid contains a **cycle**.

A cycle is defined as:
- A path of **at least 4 cells**
- All cells have the **same character**
- You can move **up, down, left, or right**
- The path starts and ends at the same cell
- You cannot reuse the same edge immediately (no trivial backtracking)

If any such cycle exists, return `true`, otherwise return `false`.

---

## Core Idea

This problem is solved using **Depth-First Search (DFS)** with:
- **Visited tracking**
- **Parent cell tracking**
- **Timestamp-based cycle detection**

Instead of just marking visited/unvisited, we store **when** a cell was visited.  
This allows us to check whether we are revisiting a cell after a sufficient path length.

---

## Key Observations

- A valid cycle must have length **≥ 4**
- Revisiting a cell too early does **not** form a cycle
- Parent tracking avoids false cycles caused by immediate backtracking

---

## Approach

### 1. Use DFS for each unvisited cell
For every cell that hasn’t been visited:
- Start DFS
- Try to expand in all four directions

### 2. Track visit order
- Maintain a `visited` matrix storing the time step when a cell was first visited
- Increment a global counter on each visit

### 3. Detect a cycle
If during DFS:
- You reach a cell already visited
- And the difference in visit times is **≥ 3**

Then a valid cycle exists.

---

## Algorithm Steps

1. Initialize a `visited` matrix with zeros
2. Traverse each cell of the grid
3. For unvisited cells, start DFS
4. In DFS:
   - Stop if out of bounds or character mismatches
   - If revisiting a cell, check cycle length
   - Otherwise mark visit time and continue DFS
5. Return `true` if any DFS finds a cycle

---

## Java Code Implementation

```java
class Solution {

    private int time = 1;

    private boolean explore(char[][] board, int r, int c,
                            int[][] seen, int pr, int pc, char color) {

        // Out of bounds or different character
        if (r < 0 || c < 0 || r >= board.length || c >= board[0].length)
            return false;
        if (board[r][c] != color)
            return false;

        // Cycle detection (length >= 4)
        if (seen[r][c] != 0) {
            return time - seen[r][c] >= 3;
        }

        seen[r][c] = time++;

        // Explore neighbors while avoiding immediate parent
        if ((r + 1 != pr || c != pc) && explore(board, r + 1, c, seen, r, c, color))
            return true;

        if ((r - 1 != pr || c != pc) && explore(board, r - 1, c, seen, r, c, color))
            return true;

        if ((r != pr || c + 1 != pc) && explore(board, r, c + 1, seen, r, c, color))
            return true;

        if ((r != pr || c - 1 != pc) && explore(board, r, c - 1, seen, r, c, color))
            return true;

        return false;
    }

    public boolean containsCycle(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        int[][] visited = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visited[i][j] == 0) {
                    if (explore(grid, i, j, visited, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
}
