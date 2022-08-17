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
     vector<int>v;
    void f(TreeNode* root){
      if(root && root->left && root->right){
            if(root->left->val != root->right->val){
                v.push_back(max(root->left->val, root->right->val));
            }
           f(root->left);
            f(root->right);
        }
       
    }
    int findSecondMinimumValue(TreeNode* root) {
      
       f(root);
        sort(v.begin(), v.end());
        if(v.size()==0)
            return -1;
        return v[0];
        //return -1;
    }
};