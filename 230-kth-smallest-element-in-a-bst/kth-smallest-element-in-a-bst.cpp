/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> temp;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return temp[k-1];
    }
};