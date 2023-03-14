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
    void inorder(TreeNode* root,int num, int &sum){
        if(root == NULL){
            return ;
        }
        if(!root->left && !root->right){
            num = num*10+root->val;
           // cout<<num<<endl;
            sum = sum+num;
           // cout<<sum<<endl;
            return;
        }
        inorder(root->left, num*10+root->val,sum);
        cout<<num<<endl;
        inorder(root->right, num*10+root->val, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum =0;
        inorder(root, 0, sum);
        return sum;
    }
};