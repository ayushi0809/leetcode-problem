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
    bool f(TreeNode* root, long long leftvalue, long long rightvalue){
        if(!root)
            return true;
        if(root->val<=leftvalue || root->val >= rightvalue )
            return false;
        return f(root->left,leftvalue,root->val) && f(root->right,root->val,rightvalue);
    }
    bool isValidBST(TreeNode* root) {
        return f(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
};