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
    int leftheight(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1+leftheight(root->left);
    }
    int rightheight(TreeNode* root){
         if(root == NULL)
            return 0;
        return 1+rightheight(root->right);
    }
    int count =0;
    int countNodes(TreeNode* root) {
      if(root == NULL)
          return 0;
        int l = leftheight(root);
        int r = rightheight(root);
        if(l==r)
            return pow(2,l)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};