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
    TreeNode* parent1 =NULL;
    TreeNode* parent2 = NULL;
    int level1;
    int level2;
    void f(TreeNode* root, int depth, TreeNode* parent,int x, int y){
        if(root == NULL){
            return;
        }
        if(root->val == x || root->val == y){
            if(!parent1){
                parent1 = parent;
                level1 = depth;
            }
            else{
                parent2 =parent;
                level2 = depth;
            }
        }
        f(root->left, depth+1, root, x,y);
        f(root->right,depth+1,root,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        f(root, 0, NULL, x,y);
        if(parent1 && parent2 && parent1->val != parent2->val && level1 == level2){
            return true;
        }
        return false;
    }
};