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
    //int ans = INT_MIN;
    pair<int,int> f(TreeNode* root){
        if(!root->left && !root->right)
            return {root->val, 0};
        else if(!root->left){
            auto r = f(root->right);
            return {root->val+r.second, max(r.first,r.second)};
        }
       else if(!root->right){
            auto l = f(root->left);
            return {root->val+l.second, max(l.first,l.second)};
        }
        
            auto left = f(root->left);
            auto right = f(root->right);
            return {root->val+left.second+right.second, max(left.first, left.second)+max(right.first, right.second)};
       
        
    }
    int rob(TreeNode* root) {
        auto ans = f(root);
        return max(ans.first, ans.second);
    }
};