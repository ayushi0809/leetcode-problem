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
   // unordered_map<TreeNode*,int>m;
    int ans =0;
    int f(TreeNode* root){
        if(root==NULL)
            return 0;
       int l = f(root->left);
        int r = f(root->right);
        int val1=0;
        int val2 =0;
        if(root->left && root->left->val == root->val){
            val1 = val1+l+1;
        }
        if(root->right && root->right->val == root->val){
            val2 = val2+r+1;
        }
        ans = max(ans, val1+val2);
        return max(val1,val2);
    }
    int longestUnivaluePath(TreeNode* root) {
      f(root);
        //int ans =0;
        return ans;
    }
};