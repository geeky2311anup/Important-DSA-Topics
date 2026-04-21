/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class FindElements {
private:
    // We use an unordered_set to store recovered values.
    // This allows the find() operation to run in O(1) average time complexity,
    // rather than traversing the tree every time we search for a value.
    unordered_set<int> values; 

    /**
     * Helper function: Performs a Pre-order traversal to restore node values.
     * @param node The current node being processed.
     * @param value The value that should be assigned to this node based on its parent.
     */
    void recover(TreeNode* node, int value) {
        // Base case: If we reach a null child, stop the recursion.
        if (!node) return;

        // 1. Assign the calculated correct value to the current node.
        node->val = value;

        // 2. Insert the value into our hash set for future O(1) lookups.
        values.insert(value);

        // 3. Recurse to the left child. 
        // Formula: left_child = 2 * current_val + 1
        recover(node->left, 2 * value + 1);

        // 4. Recurse to the right child.
        // Formula: right_child = 2 * current_val + 2
        recover(node->right, 2 * value + 2);
    }

public:
    /**
     * Constructor: Rebuilds the tree logic immediately upon instantiation.
     * The input 'root' is initially contaminated (all values are -1).
     */
    FindElements(TreeNode* root) {
        // The problem definition states the root must be recovered as 0.
        if (root) {
            recover(root, 0);
        }
    }
    
    /**
     * Checks for the existence of a target value.
     * @param target The integer to search for in the recovered tree.
     * @return True if the value was assigned during the recover() process.
     */
    bool find(int target) {
        // unordered_set::count returns 1 if the element exists, 0 otherwise.
        return values.count(target);
    }
};
