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
    vector<TreeNode*>ans;
    void dfs(TreeNode* &root,   unordered_set<int>st){
        if(!root){
            return;
        }
        dfs(root->left,st);
        
        dfs(root->right,st);
        
        if(st.find(root->val) != st.end()){
          
        if(root->left)ans.push_back(root->left);
        if(root->right)ans.push_back(root->right);
        cout<<root->val<<endl;
        root=NULL;
        delete root;
            
        
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st(to_delete.begin(),to_delete.end());
        dfs(root,st);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};