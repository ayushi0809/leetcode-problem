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
    pair<bool,int> height(TreeNode* root){
         if(root == NULL){
            return make_pair(true, 0);
        }
        auto l = height(root->left);
        auto r = height(root->right);
        bool balance = (l.first && r.first && abs(l.second-r.second)<=1);
        return make_pair(balance,max(l.second,r.second)+1);
    }
    bool isBalanced(TreeNode* root) {
        auto it = height(root);
        return it.first;
    }
};