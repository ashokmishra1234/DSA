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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,map<int,vector<int>>> mp;
        queue<tuple<int,int,TreeNode*>> q;
        q.push({0,0,root});
        int level=0;
        while(!q.empty()){
            int size=q.size();
            level=level+1;
            while(size--){
                auto [v,l,node]=q.front();
                q.pop();
                mp[v][l].push_back(node->val);
                if(node->left) q.push({v-1,level,node->left});
                if(node->right) q.push({v+1,level,node->right});
            }
        }
        for(auto [v,temp]:mp){
            vector<int> res;
            for(auto [l,vec]:temp){
                sort(vec.begin(),vec.end());
                for(auto ele:vec) res.push_back(ele);
            }
            ans.push_back(res);
        }
        return ans;
    }
};