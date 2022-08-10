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
    TreeNode* bst(vector<int> &nums, int f, int l){
        if(f>l){
            return NULL;
        }
            else{
                struct TreeNode* root;
                int mid = (f+l)/2;
                root = new TreeNode(nums[mid]);
                root->left = bst(nums, f, mid-1);
                root->right = bst(nums, mid+1, l);
                return root;
            }
        }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        struct TreeNode* root;
        root = bst(nums, 0, nums.size()-1);
        return root;
    }
};