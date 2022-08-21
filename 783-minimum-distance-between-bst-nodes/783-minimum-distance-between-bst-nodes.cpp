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
    int ans = INT_MAX;
    int value;
    bool flag = false;
    void f(TreeNode* root){
        if(root == NULL){
            return;
        }
        f(root->left);
        if(!flag){
            value = root->val;
            flag = true;
        }
        else{
            ans = min(ans, root->val-value);
            value = root->val;
        }
        
        f(root->right);
        
    }
    int minDiffInBST(TreeNode* root) {
        f(root);
        return ans;
    }
};