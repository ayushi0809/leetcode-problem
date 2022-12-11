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
    int ans;
    int sum(TreeNode* root, int &res){
        if(root == NULL)
            return 0;
        int l = sum(root->left, res);
        int r = sum(root->right, res);
        
        int tem = max(max(l,r)+root->val, root->val);
         ans = max(tem, l+r+root->val);
        res = max(res, ans);
        
        return tem;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        sum(root, res);
        return res;
    }
};