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
    int p;
    
    TreeNode* f(vector<int>& postorder, int l, int r,unordered_map<int,int>&m ){
        if(l>r || p<0)
            return NULL;
        cout<<p<<endl;
        int value = postorder[p];
        TreeNode* root = new TreeNode(value);
        p--;
        root->right = f(postorder, m[value]+1, r,m);
        root->left = f(postorder,l,m[value]-1,m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        p=postorder.size()-1;
        unordered_map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]]=i;
        }
        int s = postorder.size()-1;
        return f(postorder, 0, s,m);
    }
};