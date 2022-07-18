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
        if(root != NULL){
            f(root->left);
            v.push_back(root->val);
            f(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
      f(root);
        //cout<<v[1]<<endl;
        int i =0;
        int j = v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k){
                return true;
                break;
            }
            if(v[i]+v[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};