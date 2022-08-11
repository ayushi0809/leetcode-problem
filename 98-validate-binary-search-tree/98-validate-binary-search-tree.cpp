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
    vector<int> Inorder(TreeNode *root , vector<int> &arr){
        if(root!=NULL){
            Inorder(root->left, arr);
            arr.push_back(root->val);
            Inorder(root->right, arr);
        }
        return arr;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
      Inorder(root, v);
        set<int> s(v.begin(), v.end());
        if(is_sorted(v.begin(), v.end()) && (s.size() == v.size())){
            return true;
        }
           else{
               return false;
           }
    }
};