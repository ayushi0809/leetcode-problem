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
    TreeNode* deleteNode(TreeNode* root, TreeNode* parent, int target, bool l , bool r){
        if(root==NULL)
            return root;
       
        deleteNode(root->left, root, target, true, false);
         if(root->val==target && !root->left && !root->right ){
            if(l){
                parent->left =NULL;
            }
            if(r){
                parent->right= NULL;
            }
        }
        deleteNode(root->right,root,target,false,true);
         if(root->val==target && !root->left && !root->right ){
            if(l){
                parent->left =NULL;
            }
            if(r){
                parent->right= NULL;
            }
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
         deleteNode(root, NULL, target, false, false);
        if(root->val==target && !root->left && !root->right)
            return NULL;
        return root;
    }
};