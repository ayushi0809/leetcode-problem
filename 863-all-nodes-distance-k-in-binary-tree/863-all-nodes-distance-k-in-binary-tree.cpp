/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*>v;
    bool f(TreeNode* root, TreeNode* target){
        if(root == NULL)
            return false;
        if(root->val == target->val){
            v.push_back(root);
            return true;
        }
        bool l = f(root->left, target);
        if(l){
            v.push_back(root);
            return true;
        }
         bool r = f(root->right, target);
         if(r){
            v.push_back(root);
            return true;
        }
        return false;
    }
    vector<int>ans;
    void print(TreeNode* root, int k, TreeNode* prev){
        if(root==NULL || k<0 || root == prev){
            return;
        }
        if(k==0){
            ans.push_back(root->val);
        }
        print(root->left,k-1,prev);
        print(root->right,k-1,prev);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        f(root,target);
        int n = v.size();
        for(int i =0; i<n; i++){
            cout<<v[i]->val<<endl;
            print(v[i],k-i, i==0?NULL:v[i-1]);
        }
        return ans;
    }
};