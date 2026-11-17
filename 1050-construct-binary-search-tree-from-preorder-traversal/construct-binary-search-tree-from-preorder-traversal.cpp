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
    int idx = 0;

    TreeNode* build(vector<int>& preorder,
                    long long mini,
                    long long maxi) {

        // All elements processed
        if (idx == preorder.size()) {
            return NULL;
        }

        // Current value does not belong to this subtree
        if (preorder[idx] <= mini || preorder[idx] >= maxi) {
            return NULL;
        }

        // Create current node
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        // Construct left subtree
        root->left = build(preorder, mini, root->val);

        // Construct right subtree
        root->right = build(preorder, root->val, maxi);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx = 0;
        return build(preorder, LLONG_MIN, LLONG_MAX);
    }
};
