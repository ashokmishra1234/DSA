class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if (curr->right != nullptr) {
            pushAllLeft(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */