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
    int geth_l(TreeNode* node){
        if(!node) return 0;
        return 1+geth_l(node->left);
    }
    int geth_r(TreeNode* node){
        if(!node) return 0;
        return 1+geth_r(node->right);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=geth_l(root);
        int rh=geth_r(root);
        if(lh==rh) return pow(2,lh)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};