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
    bool dfs(TreeNode* root, int target){
        if(root == NULL)
            return 0;
        bool ans = 0;
        target= target-root->val;
        if(target==0 && !root->left && !root->right){
            return 1;
        }
        ans = ans || dfs(root->left,target);
        ans = ans || dfs(root->right,target);
        return ans;
            
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
    }
};