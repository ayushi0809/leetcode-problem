#define mod 1000000007;
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

    unordered_map<TreeNode*, long>m;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            m[root] = root->val;
        }

        else if(!root->right && root->left){
            dfs(root->left);
            m[root] = root->val+m[root->left];
        }

        else if(root->right && !root->left){
            dfs(root->right);
            m[root] = root->val+m[root->right];
        }

        else{
            dfs(root->left);
            dfs(root->right);
            m[root] = m[root->left]+root->val+m[root->right];
        }
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        long  total_sum = m[root];
        long maxi = LONG_MIN;
        for(auto it = m.begin(); it != m.end(); it++){
            maxi = max(maxi, (total_sum-it->second)*it->second);
        }

        return int(maxi%1000000007);
    }
};