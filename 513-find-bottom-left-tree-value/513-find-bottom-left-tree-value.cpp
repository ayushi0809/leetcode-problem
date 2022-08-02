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
        if(root == NULL)
            return 0;
        return max(height(root->left), height(root->right))+1;
    }
    int findBottomLeftValue(TreeNode* root) {
        int h = height(root)-1;
        queue<TreeNode*>q;
        q.push(root);
        int i =0;
        cout<<h<<endl;
        while(!q.empty()){
            int s = q.size();
            if(i==h){
                return q.front()->val;
            }
            i++;
            while(s){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
                s--;
            }
        }
        return q.front()->val;
    }
};