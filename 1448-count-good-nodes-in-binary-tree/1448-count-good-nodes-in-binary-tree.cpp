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
    int count =0;
    void f(TreeNode* root, int maxi){
        if(!root){
            return;
        }
        maxi = max(maxi,root->val);
        if(maxi==root->val)
            count++;
        f(root->left,maxi);
        f(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        f(root,INT_MIN);
        return count;
        
    }
};