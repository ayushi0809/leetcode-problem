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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty()){
            int s = q.size();
            while(s){
                TreeNode* x = q.front();
                q.pop();
                if(s==1){
                    v.push_back(x->val);
                }
                s--;
            if(x->left){
                q.push(x->left);
            }
                if(x->right){
                    q.push(x->right);
                }
            }
        }
        return v;
    }
};