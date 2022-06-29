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
    void f(TreeNode* root, int targetSum, int &count, vector<int> &v){
        if(root == NULL)
            return;
        v.push_back(root->val);
        f(root->left,targetSum,count,v);
        f(root->right,targetSum,count,v);
        int i = v.size()-1;
        //cout<<v[v.size()-1]<<endl;
        long long int sum=0;
        while(i>=0){
            sum = sum+v[i--];
            if(sum==targetSum){
                count = count+1;  
            }   
           
        }
         v.pop_back(); 
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        int sum=0;
        int count=0;
        f(root,targetSum,count,v);
        return count;
        
    }
};