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
    bool f(TreeNode* root, TreeNode* prev, bool isleft, bool isright ){
        if(root == NULL){
            return true;
        }
        int l = f(root->left, root, true, false);
        int r = f(root->right, root, false, true);
        
        if(l && r && root->val == 0){
            if(prev == NULL){
                root = NULL;
                
            }
            if(isleft){
                prev->left = NULL;
            }
            if(isright){
                prev->right = NULL;
            }
            return true;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
    if(f(root, NULL, false,false)==1){
        return NULL;
    }
        return root;
    }
};