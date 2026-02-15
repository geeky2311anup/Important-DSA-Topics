#include <unordered_set>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
