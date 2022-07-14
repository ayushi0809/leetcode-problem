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
    int p = 0;
    TreeNode* f(vector<int> &preorder,  unordered_map<int,int> &m, int l, int r){
        if(l>r){
            return NULL;
        }
            int value = preorder[p];
            TreeNode* root = new TreeNode(value);
            p++;
            root->left =f(preorder, m,l,m[value]-1 );
            root->right= f(preorder,m,m[value]+1, r);
            return root;
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return f(preorder, m, 0, preorder.size()-1);
    }
};