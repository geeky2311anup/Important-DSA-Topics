TreeNode* recoverFromPreorder(string traversal) {
    stack<TreeNode*> st;
    int i = 0, n = traversal.size();

    while (i < n) {
        // Step 1: Count the number of dashes (depth level)
        int depth = 0;
        while (i < n && traversal[i] == '-') {
            depth++;
            i++;
        }

        // Step 2: Read the number (node value)
        int num = 0;
        while (i < n && isdigit(traversal[i])) {
            num = num * 10 + (traversal[i] - '0');
            i++;
        }

        // Step 3: Create the new node
        TreeNode* node = new TreeNode(num);

        // Step 4: Adjust stack to find the parent
        while (st.size() > depth) {
            st.pop();
        }

        // Step 5: Attach as left or right child
        if (!st.empty()) {
            if (!st.top()->left) {
                st.top()->left = node;
            } else {
                st.top()->right = node;
            }
        }

        // Step 6: Push the current node to stack
        st.push(node);
    }

    // The root of the tree is the bottom-most element in the stack
    while (st.size() > 1) {
        st.pop();
    }
    return st.top();
}
