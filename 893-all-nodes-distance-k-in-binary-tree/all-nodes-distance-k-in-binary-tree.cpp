/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void make_parent(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return;
    }
    vector<int> distance(TreeNode* root, TreeNode* target, int k,
                         unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> st;
        q.push(target);
        st.insert(target);
        int dist = 0;
        while (!q.empty()) {
            if (dist == k)
                break;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    if (st.find(node->left) == st.end()) {
                        q.push(node->left);
                        st.insert(node->left);
                    }
                }
                if (node->right) {
                    if (st.find(node->right) == st.end()) {
                        q.push(node->right);
                        st.insert(node->right);
                    }
                }
                if (parent.find(node) != parent.end()) {
                    if (st.find(parent[node]) == st.end()) {
                        q.push(parent[node]);
                        st.insert(parent[node]);
                    }
                }
            }
            dist += 1;
        }
        vector<int> ans;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
        
    }
        vector<int> distanceK(TreeNode * root, TreeNode * target, int k) {
            unordered_map<TreeNode*, TreeNode*> parent;
            make_parent(root, parent);
            vector<int> ans = distance(root, target, k, parent);
            return ans;
        }
    };