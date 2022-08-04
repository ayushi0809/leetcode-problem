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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    void dfs(TreeNode* root, vector<vector<string>>&v, int r, int c,int h){
        cout<<r<<" "<<c<<endl;
        if(root == NULL)
            return ;
        if(!root->left && !root->right){
            v[r][c] = to_string(root->val);
            return;
        }
        dfs(root->left, v,r+1,c-pow(2,(h-r-1)),h);
        dfs(root->right,v,r+1, c+pow(2,(h-r-1)),h);
        
        
        v[r][c] = to_string(root->val);
        
        
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int m =h;
        int n = pow(2,(h))-1;
        int c = (n-1)/2;
        vector<vector<string>>v(m, vector<string>(n, ""));
        dfs(root, v, 0, c, h-1);
        return v;
        
    }
};