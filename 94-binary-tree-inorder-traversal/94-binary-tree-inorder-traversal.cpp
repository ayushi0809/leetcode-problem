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
    TreeNode* rightmostnode(TreeNode* leftnode, TreeNode* curr){
        while(leftnode->right != NULL && leftnode->right != curr){
            leftnode= leftnode->right;
        }
        return leftnode;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
       while(root != NULL){
           TreeNode* leftnode = root->left;
           if(leftnode == NULL){
               v.push_back(root->val);
               root = root->right;
           }else{
               TreeNode* rightnode = rightmostnode(leftnode, root);
               if(rightnode->right==NULL){
                   rightnode->right = root;
                   root = root->left;
               }else{
                   rightnode->right = NULL;
                   v.push_back(root->val);
                   root = root->right;
               }
           }
       }
        return v;
    }
};