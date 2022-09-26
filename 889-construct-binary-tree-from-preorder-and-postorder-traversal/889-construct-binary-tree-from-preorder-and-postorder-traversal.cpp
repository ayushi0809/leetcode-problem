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
    TreeNode* f(unordered_map<int,int> &m, int prestart, int preend, int poststart, int postend, vector<int>& preorder){
        
       if(prestart>preend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart==preend)return root;
        int index = m[preorder[prestart+1]];
        int leftcount = index-poststart;
        
        root->left = f(m,prestart+1,prestart+leftcount+1,poststart,index,preorder);
        root->right = f(m, prestart+leftcount+2, preend, index+1,postend-1,preorder);
        
      
    return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        
        for(int i =0; i<postorder.size(); i++){
            m[postorder[i]] = i;
        }
        int n = preorder.size();
       return f(m,0,n-1,0,n-1,preorder);
        
        
        
    }
};