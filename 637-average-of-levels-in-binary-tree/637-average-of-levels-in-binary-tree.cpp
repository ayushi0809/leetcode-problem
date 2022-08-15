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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            double d = s;
            double sum =0.0;
            while(s){
                TreeNode* x = q.front();
                q.pop();
                sum = sum+x->val;
                    if(x->left){
                        q.push(x->left);
                    }
                if(x->right){
                    q.push(x->right);
                }
               s--; 
            }
            cout<<sum<<endl;
            double a = sum/d;
            ans.push_back(a);
        }
       return ans; 
    }
};