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
    //string s;
    string f(TreeNode* root, string s){
        if(root == NULL)
            return "";
        else if(!root->left && !root->right){
            s = s+'('+to_string(root->val)+')';
            return s;
        }
        else if(root->left==NULL){
           string g =  f(root->right,s);
            s=s+'('+to_string(root->val)+'('+')'+g+')';
            return s;
        }
        else if(root->right == NULL){
            string h = f(root->left,s);
            s=s+'('+to_string(root->val)+h+')';
            return s;
        }
        else{
            s=s+'('+to_string(root->val)+f(root->left,s)+f(root->right,s)+')';
        }
        return s;
    }
    string tree2str(TreeNode* root) {
       string res =  f(root, "");
        res.pop_back();
        res.erase(0,1);
        return res;
    }
};