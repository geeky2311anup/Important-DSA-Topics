# 😅 Was this really a tree problem… or just level-wise addition in disguise?

---

## 🧠 Problem Name  
**Maximum Level Sum of a Binary Tree**

---

## 🎯 Intuition — what you want to do  
> You are given a **binary tree**.  
>  
> Each level of the tree has several nodes.  
>  
> Your task is simple:
> 👉 **Find the level number whose node values sum up to the maximum.**

So basically:
- Level 1 → sum of root  
- Level 2 → sum of children  
- Level 3 → sum of grandchildren  
- …  
Return the **level index** (1-based) having the **maximum sum**.

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse the tree **level by level**  
> - Keep track of:
>   - which level a node belongs to  
>   - cumulative sum at each level  
> - After traversal, pick the level with the **largest total sum**

Why level-order traversal?
> Because levels matter more than structure here.

---

## 🧠 Why this works  
> - Breadth-First Search (BFS) naturally visits nodes level by level  
> - By storing `(node, level)` together:
>   - every node contributes to exactly one level  
> - A map lets us accumulate sums cleanly  
> - One final scan over the map gives the best level

No recursion depth issues.  
No unnecessary complexity.  
Just **clean BFS + bookkeeping**.

---

## 🔧 Approach (matching the implementation)

### 1️⃣ Use BFS with a queue  
> Each queue entry stores:
> - the current node  
> - its level number  

---

### 2️⃣ Accumulate sums per level  
> Use a map:
> - key → level  
> - value → sum of node values at that level  

Every time you pop from the queue:
> add `node.val` to `map[level]`

---

### 3️⃣ Push children with level + 1  
> If left/right child exists:
> - enqueue it with `level + 1`

---

### 4️⃣ Find the level with maximum sum  
> Iterate over the map:
> - track the maximum sum  
> - return the corresponding level

---

## 🔍 What each component contributes

### `pair (TreeNode, level)`
> Binds a node with its depth so we never lose track of levels.

### `Queue`
> Ensures level-order traversal (BFS).

### `Map<Integer, Integer>`
> Stores cumulative sum per level.

### `ans`
> Tracks the maximum sum found so far.

### `ind`
> Stores the level index corresponding to `ans`.

---

## 🧪 Dry Run (example)
```
Tree:

  1
 / \
7  -8
```


Level sums:
- Level 1 → 1
- Level 2 → 7 + (-8) = -1

👉 Maximum sum = **1**  
👉 Answer = **Level 1**

---

## 📊 Complexity

> **Time Complexity:** `O(n)`  
> (each node visited once)

> **Space Complexity:** `O(n)`  
> (queue + map in worst case)

---

## 💻 Code

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 * }
 */

// Helper class to store node along with its level in the tree
class Pair {
    TreeNode node;
    int level;

    Pair(TreeNode node, int level) {
        this.node = node;
        this.level = level;
    }
}

class Solution {
    public int maxLevelSum(TreeNode root) {

        // Map to store sum of values at each level
        // key = level number, value = sum of that level
        Map<Integer, Integer> levelSum = new HashMap<>();

        // Queue for BFS traversal (level order traversal)
        Queue<Pair> queue = new LinkedList<>();

        // Start BFS from root at level 1
        queue.add(new Pair(root, 1));

        // Standard BFS loop
        while (!queue.isEmpty()) {
            Pair cur = queue.poll();

            TreeNode node = cur.node;
            int lvl = cur.level;

            // Add current node's value to its level sum
            levelSum.put(lvl, levelSum.getOrDefault(lvl, 0) + node.val);

            // Push left child with incremented level
            if (node.left != null) {
                queue.add(new Pair(node.left, lvl + 1));
            }

            // Push right child with incremented level
            if (node.right != null) {
                queue.add(new Pair(node.right, lvl + 1));
            }
        }

        // Find the level with maximum sum
        int maxSum = Integer.MIN_VALUE;
        int answerLevel = 1;

        // Iterate through all levels stored in map
        for (int lvl : levelSum.keySet()) {
            int currentSum = levelSum.get(lvl);

            // Update maximum sum and corresponding level
            if (currentSum > maxSum) {
                maxSum = currentSum;
                answerLevel = lvl;
            }
        }

        // Return the level having maximum sum
        return answerLevel;
    }
}
