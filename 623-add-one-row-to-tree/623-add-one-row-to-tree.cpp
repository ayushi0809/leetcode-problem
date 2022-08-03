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
    unordered_map<TreeNode*, int>m;
    void f(TreeNode* root, int d, int val, int depth){
        if(root==NULL)
            return;
        if(d==depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = new TreeNode(val);
            root->left->left= left;
            root->right = new TreeNode(val);
            root->right->right = right;
        }
        else{
            f(root->left, d+1, val,depth);
            f(root->right, d+1, val,depth);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth ==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        f(root, 1, val,depth);
        return root;
    }
};