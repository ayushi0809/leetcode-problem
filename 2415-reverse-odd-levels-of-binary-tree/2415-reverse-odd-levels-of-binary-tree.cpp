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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
       // vector<int>v;
        q.push(root);
        int level =0;
        while(!q.empty()){
            vector<int>v;
            vector<TreeNode*>node;
            int n = q.size();
            while(n){
                TreeNode* x = q.front();
                q.pop();
                node.push_back(x);
                v.push_back(x->val);
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
                n--;
            }
            if(level%2==1){
                for(int i = v.size()-1; i>=0; i--){
                    TreeNode* x = node[v.size()-i-1];
                    x->val = v[i];   
                }
            }
            level= level+1;
        }
        return root;
    }
};