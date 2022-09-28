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
    int count =0;
    void dfs(TreeNode* root){
        if(!root)
            return ;
        else if(!root->left && !root->right){
            m[root] = {root->val, 1};
            count++;
        }
        else if(root->left && !root->right){
            dfs(root->left);
            m[root] = {m[root->left].first+root->val, m[root->left].second+1};
            if(floor(m[root].first/m[root].second)==root->val){
                count++;
            }
        }
        else if(!root->left && root->right){
            dfs(root->right);
            m[root] = {m[root->right].first+root->val, m[root->right].second+1};
            if(floor(m[root].first/m[root].second)==root->val){
                count++;
            }
        }
            
        else{
            dfs(root->left);
             dfs(root->right);
            int sum = m[root->left].first+m[root->right].first+root->val;
            int c = m[root->left].second+m[root->right].second+1;
            
            m[root] = {sum,c};
            if(floor(sum/c)==root->val){
                count++;
            }
            
        }
        
    }
    int averageOfSubtree(TreeNode* root) {
     dfs(root);
        return count;
    }
};