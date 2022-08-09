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
    unordered_map<TreeNode*, bool>m;
    bool isidentical(TreeNode* root, TreeNode* subroot){
        if(!root && !subroot)
            return true;
        if(!root && subroot){
            return false;
        }
        if(root && !subroot){
            return false;
        }
       if(root->val != subroot->val)
           return false;
        
        bool l = isidentical(root->left, subroot->left);
        bool r = isidentical(root->right, subroot->right);
        
        bool ans = (root->val==subroot->val) && l && r;
        
        return ans;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root && !subroot)
            return true;
        if(!root && subroot){
            return false;
        }
        if(root && !subroot){
            return false;
        }
        return isidentical(root,subroot) || isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
};