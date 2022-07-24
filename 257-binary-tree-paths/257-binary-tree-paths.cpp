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
    vector<string>v;
    
    void path(TreeNode* root, string res){
        
        if(root==NULL){
            return ;
        }
        res = res+to_string(root->val)+"->";
        
        if(!root->right && !root->left){
       // res = res+to_string(root->val);
            res.pop_back();
            res.pop_back();
        v.push_back(res);
        
        }
        path(root->left,res);
        path(root->right,res);
        res.pop_back();
        
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        path(root, "");
        return v;
        
    }
};