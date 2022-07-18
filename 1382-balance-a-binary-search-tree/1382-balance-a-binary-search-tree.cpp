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
    TreeNode* balance(TreeNode* root, int l, int r){
        if(l>r)
            return NULL;
        int mid = (r+l)/2;
        root = new TreeNode(v[mid]);
        //return root;
        cout<<v[mid]<<endl;
        root->left = balance(root, l, mid-1);
        root->right = balance(root, mid+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
       
       f(root);
         int l =0;
        int r = v.size()-1;
        int mid = (l+r)/2;
        TreeNode* rt = new TreeNode(v[mid]);
       return  balance(rt, l,r);
    }
};