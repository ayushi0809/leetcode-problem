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
   void f(TreeNode* root, int targetSum, vector<vector<int>> &res, vector<int> &v){
       if(root == NULL)
           return;
        if(!root->left && !root->right && targetSum-root->val==0){
            v.push_back(root->val);
            res.push_back(v);
            //cout<<res[0][0]<<endl;
            v.pop_back();
            return;
        }
       
        v.push_back(root->val);
       //cout<<v[0]<<endl;
        f(root->left,targetSum-root->val,res,v);
        f(root->right,targetSum-root->val,res, v);
       v.pop_back();
        
       // return res;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>v;
        f(root,targetSum,res,v);
        return res;
    }
};