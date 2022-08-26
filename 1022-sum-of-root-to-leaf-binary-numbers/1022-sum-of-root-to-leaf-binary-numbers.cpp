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
    
    int sum =0;
    
    void f(TreeNode* root, string s){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            s=s+to_string(root->val);
            sum = sum + stoi(s, 0, 2);
            //return true;
        }
       f(root->left, s+to_string(root->val));
        f(root->right, s+to_string(root->val));
        //return false;
    }
    int sumRootToLeaf(TreeNode* root) {
        f(root,"");
        
        return sum;
    }
};