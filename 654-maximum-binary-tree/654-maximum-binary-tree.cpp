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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        auto ans = max_element(nums.begin(), nums.end());
        //cout<<*ans<<endl;
        if(ans == nums.end())
            return NULL;
        TreeNode* root = new TreeNode(*ans);
        vector<int>left(nums.begin(), ans);
        vector<int>right(ans+1, nums.end());
        //cout<<right[0]<<endl;
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        
        return root;
        
    }
};