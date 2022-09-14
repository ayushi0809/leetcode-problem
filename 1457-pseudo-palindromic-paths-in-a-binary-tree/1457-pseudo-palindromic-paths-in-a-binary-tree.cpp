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
    int count=0;
    void dfs(TreeNode* root, vector<int>v,int ans){
        if(!root)
            return;
        if(!root->left && !root->right){
            v[root->val]++;
            int c =0;
           for(int i =1; i<10; i++){
               if(v[i]%2==1)
               {
                   //cout<<i;
                   c++;
               }
           }
            if(c<=1)
                count++;
            return;
        }
        v[root->val]++;
        ans = ans^root->val;
        
        dfs(root->left,v,ans);
        dfs(root->right,v,ans);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        //v[8]++;
        dfs(root,v,0);
        return count;
        
        
    }
};