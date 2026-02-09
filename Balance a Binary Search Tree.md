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
