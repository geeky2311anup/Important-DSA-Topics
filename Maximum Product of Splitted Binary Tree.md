# Maximum Product of Splitted Binary Tree

## Problem Overview
Given the root of a binary tree, split the tree into two subtrees by removing exactly one edge.  
Return the **maximum product** of the sums of the two resulting subtrees.  
Since the answer can be very large, return it **modulo `10^9 + 7`**.

---

## Key Observations
- Removing one edge divides the tree into:
  - a subtree with sum `s`
  - the remaining tree with sum `totalSum - s`
- The product for this split is:
s × (totalSum − s)


- To find the maximum product:
- We must evaluate this product for **every possible subtree**
- **Modulo must NOT be applied before comparison**, otherwise ordering is broken

---

## Approach (Two DFS Traversals)

### 1. Compute Total Tree Sum
Use DFS to calculate the sum of all nodes in the tree.

### 2. Compute Maximum Product
Perform another DFS:
- For each node, compute its subtree sum `s`
- Calculate the product `s × (totalSum − s)`
- Track the maximum product globally

---

## Important Implementation Details
- Use `long` for sums and products to avoid overflow
- Compare **raw products**, not modulo values
- Apply modulo **only once** at the final return
- Never return `s % mod` from recursion — always return the real subtree sum

---

## Algorithm
1. DFS to compute `totalSum`
2. DFS again to:
 - compute subtree sum `s`
 - update `maxProduct = max(maxProduct, s × (totalSum − s))`
3. Return `maxProduct % mod`

---

## Correct Java Implementation

```java
class Solution {
  long ans = 0;
  int mod = 1_000_000_007;

  // First DFS: compute total sum of tree
  public long sum(TreeNode root) {
      if (root == null) return 0;
      return sum(root.left) + sum(root.right) + root.val;
  }

  // Second DFS: compute subtree sums and max product
  public long bestProduct(TreeNode root, long totalSum) {
      if (root == null) return 0;

      long left = bestProduct(root.left, totalSum);
      long right = bestProduct(root.right, totalSum);

      long s = left + right + root.val;
      long product = s * (totalSum - s);

      ans = Math.max(ans, product);
      return s;
  }

  public int maxProduct(TreeNode root) {
      long totalSum = sum(root);
      bestProduct(root, totalSum);
      return (int)(ans % mod);
  }
}

