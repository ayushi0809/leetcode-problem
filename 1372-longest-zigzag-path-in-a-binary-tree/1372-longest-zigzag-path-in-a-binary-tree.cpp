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
    int ans =0;
    int f(TreeNode* root, bool direction){
        if(root==NULL)
            return 0;
        int res = 1;
        if(direction){
            res =  res+f(root->left,false);
        ans =  max(1+f(root->right,true),ans);
        }
        else{
            res = res+f(root->right,true);
            ans = max(1+f(root->left, false), ans);
        }
        ans = max(ans,res);
        return res;
    }
    int longestZigZag(TreeNode* root) {
         f(root, true);
        return ans-1;
    }
};