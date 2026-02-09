class Solution {

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> values = new ArrayList<>();
        collectInorder(root, values);
        return buildBalancedTree(values, 0, values.size() - 1);
    }

    private void collectInorder(TreeNode node, List<Integer> values) {
        if (node == null) {
            return;
        }

        collectInorder(node.left, values);
        values.add(node.val);
        collectInorder(node.right, values);
    }

    private TreeNode buildBalancedTree(List<Integer> values, int left, int right) {
        if (left > right) {
            return null;
        }

        int mid = left + (right - left) / 2;
        TreeNode node = new TreeNode(values.get(mid));

        node.left = buildBalancedTree(values, left, mid - 1);
        node.right = buildBalancedTree(values, mid + 1, right);

        return node;
    }
}
You are given a Binary Search Tree (BST) that may be unbalanced.
Your task is to convert it into a balanced BST while keeping all values.

A balanced BST ensures:

Left and right subtree heights differ by at most 1

Operations like search run in O(log n) time

Key Insight

Inorder traversal of a BST gives values in sorted order.

So the plan is:

Traverse the BST in inorder → get a sorted list of values

Build a balanced BST from that sorted list

Step 1: Inorder Traversal (Sorting)
private void collectInorder(TreeNode node, List<Integer> values) {
    if (node == null) {
        return;
    }

    collectInorder(node.left, values);
    values.add(node.val);
    collectInorder(node.right, values);
}

What this does

Visits left → root → right

Because it’s a BST, values are collected in ascending order

Example:

    3
     \
      7
       \
        9


Inorder result:

[3, 7, 9]

Step 2: Build a Balanced BST from Sorted Values
private TreeNode buildBalancedTree(List<Integer> values, int left, int right) {
    if (left > right) {
        return null;
    }

    int mid = left + (right - left) / 2;
    TreeNode node = new TreeNode(values.get(mid));

    node.left = buildBalancedTree(values, left, mid - 1);
    node.right = buildBalancedTree(values, mid + 1, right);

    return node;
}

Why this works

Choosing the middle element as root ensures balance

Left half becomes left subtree

Right half becomes right subtree

Example with:

values = [1, 2, 3, 4, 5, 6, 7]


Tree built:

        4
      /   \
     2     6
    / \   / \
   1   3 5   7


Perfectly balanced 🌳

Step 3: Main Method
public TreeNode balanceBST(TreeNode root) {
    List<Integer> values = new ArrayList<>();
    collectInorder(root, values);
    return buildBalancedTree(values, 0, values.size() - 1);
}

Flow

Collect sorted values from original BST

Rebuild a new balanced BST

Return the new root

Time & Space Complexity
Aspect	Complexity
Inorder traversal	O(n)
Tree construction	O(n)
Total Time	O(n)
Extra Space	O(n)
