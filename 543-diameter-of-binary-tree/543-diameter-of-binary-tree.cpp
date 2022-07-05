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
    int d = INT_MIN;
    int height(TreeNode* node){
        // code here 
        if(node == NULL)
        return 0;
        int l = height(node->left);
        int r = height(node->right);
        d = max(d, l+r );
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return d;
    }
};