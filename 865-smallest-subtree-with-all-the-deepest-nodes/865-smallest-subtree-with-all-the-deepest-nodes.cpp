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
     int f(TreeNode* root){
         if(root  == NULL){
             return 0;
         }
         return max(f(root->left) ,f(root->right))+1;
     }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        int l = f(root->left);
        int r = f(root->right);
        if(l==r){
            return root;
        }
        if(l<r){
            return subtreeWithAllDeepest(root->right);
        }
        return subtreeWithAllDeepest(root->left);
    }
};