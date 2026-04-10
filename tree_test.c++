class FindElements {
private:
    // Set to store all recovered values for quick lookup
    unordered_set<int> values; 

    // Helper function to recover the contaminated tree
    void recover(TreeNode* node, int value) {
        // Base case: if node is null, return
        if (!node) return;

        // Assign correct value to current node
        node->val = value;

        // Store the recovered value in the set
        values.insert(value);

        // Recursively recover left child
        // Left child value = 2 * current value + 1
        recover(node->left, 2 * value + 1);

        // Recursively recover right child
        // Right child value = 2 * current value + 2
        recover(node->right, 2 * value + 2);
    }

public:
    // Constructor: initializes and recovers the tree
    FindElements(TreeNode* root) {
        // If root exists, start recovery with value 0
        if (root) recover(root, 0); 
    }
    
    // Function to check if a target value exists in the recovered tree
    bool find(int target) {
        // Returns true if target is found in the set
        return values.count(target);
    }
};
