class Solution {

    public TreeNode balanceBST(TreeNode root) {
        // Step 1: Store BST values in sorted order
        List<Integer> values = new ArrayList<>();
        collectInorder(root, values);

        // Step 2: Build a balanced BST from the sorted values
        return buildBalancedTree(values, 0, values.size() - 1);
    }

    // Inorder traversal: left → root → right
    // This gives values in sorted order for a BST
    private void collectInorder(TreeNode node, List<Integer> values) {
        // Base case: if node is null, stop recursion
        if (node == null) {
            return;
        }

        // Traverse left subtree
        collectInorder(node.left, values);

        // Visit current node
        values.add(node.val);

        // Traverse right subtree
        collectInorder(node.right, values);
    }

    // Build a balanced BST from the sorted array
    private TreeNode buildBalancedTree(List<Integer> values, int left, int right) {
        // Base case: no elements to process
        if (left > right) {
            return null;
        }

        // Choose middle element to keep tree balanced
        int mid = left + (right - left) / 2;

        // Create node with middle value
        TreeNode node = new TreeNode(values.get(mid));

        // Recursively build left subtree
        node.left = buildBalancedTree(values, left, mid - 1);

        // Recursively build right subtree
        node.right = buildBalancedTree(values, mid + 1, right);

        // Return the root of this subtree
        return node;
    }
}
