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
    void preorder(TreeNode* root, queue<int> &q){
        if(root != NULL){
            q.push(root->val);
            preorder(root->left,q);
            preorder(root->right,q);
        }
    }
    void flatten(TreeNode* root) {
        if(root != NULL){
        queue<int>q;
        preorder(root->left, q);
        preorder(root->right, q);
        root->left = NULL;
        root->right = NULL;
        TreeNode* p = root;
       while(q.empty() == false){
           p->right = new TreeNode(q.front());
           q.pop();
           p = p->right;
       }
        }
       
        
    }
};