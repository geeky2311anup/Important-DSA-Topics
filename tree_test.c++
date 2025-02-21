class FindElements {
    private:
    unordered_set<int> values; 

    void recover(TreeNode* node, int value) {
        if (!node) return;
        node->val = value;        
        values.insert(value);     

       
        recover(node->left, 2 * value + 1);
        recover(node->right, 2 * value + 2);
    }
public:
    FindElements(TreeNode* root) {
         if (root) recover(root, 0); 
    }
    
    bool find(int target) {
         return values.count(target);
    }
};
