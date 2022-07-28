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
    int camera = 0;
    int f(TreeNode* root, TreeNode* parent) {
        if(root==NULL)
            return 1;
        int l = f(root->left, root);
        int r = f(root->right,root);
        
        if(l==-1 || r==-1){
            camera = camera+1;
            return 0; 
        }
        if(l== 0 || r==0){
            return 1;
        }
        if((l==1 || r==1) && parent == NULL){
            camera++;
        return -1;
        }
        return -1;
        
    }
    int minCameraCover(TreeNode* root) {
       f(root, NULL);
        return camera;
    }
};