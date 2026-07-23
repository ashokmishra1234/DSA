/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        string to_encode="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(!node) to_encode+=("#,");
            else to_encode+=(to_string(node->val)+",");
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return to_encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        if(str=="#") return nullptr;
        TreeNode* root=new TreeNode(stoi(str));
        TreeNode* ans=root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left=nullptr;
            }else{
                TreeNode* newNode=new TreeNode(stoi(str));
                node->left=newNode;
            }
            getline(s,str,',');
            if(str=="#"){
                node->right=nullptr;
            }else{
                TreeNode* newNode=new TreeNode(stoi(str));
                node->right=newNode;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));