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
    unordered_map<TreeNode*, pair<int,int>>m;
    void dfs(TreeNode* root){
        if(root == NULL)
            return ;
        else if(!root->left && !root->right){
            m[root] = {root->val, 0};
            //return;
        }
        else if(!root->left){
            dfs(root->right);
            m[root] = {root->val+m[root->right].first, abs(0-m[root->right].first)};
            
        }
        else if(!root->left){
             dfs(root->left);
             m[root] = {root->val+m[root->left].first, abs(0-m[root->left].first)};
        }
        else{
        dfs(root->left);
        dfs(root->right);
        
        m[root] = {m[root->left].first+root->val+m[root->right].first, abs(m[root->left].first - m[root->right].first)};
    }
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        int s =0;
        for(auto it = m.begin(); it != m.end(); it++){
           auto a = it->second;
            cout<<a.first<<" "<<a.second<<endl;
            s =s +a.second;
        }
        return s;
    }
};