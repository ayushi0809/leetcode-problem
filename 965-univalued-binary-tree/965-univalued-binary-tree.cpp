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
    bool f(TreeNode* root, int node){
        if(!root){
            return true;
        }
       
        if(root->val==node){
            return f(root->left,node) && f(root->right,node);
        }
        
        return false;
        
    }
    bool isUnivalTree(TreeNode* root) {
       int node = root->val;
        return f(root,node);
        
    }
};