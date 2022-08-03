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
    unordered_map<TreeNode*, int>m;
    void f(TreeNode* root, int d){
        if(root==NULL)
            return;
        m[root] = d;
        f(root->left, d+1);
        f(root->right, d+1);
    
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        f(root,1);
        if(depth ==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        for(auto it = m.begin(); it !=m.end(); it++){
            if(it->second==depth-1){
                TreeNode* node = it->first;
                cout<<node->val<<endl;
                TreeNode* left = node->left;
                TreeNode* right = node->right;
                TreeNode* l = new TreeNode(val);
                TreeNode* r = new TreeNode(val);
                node->left = l;
                node->right = r;
                l->left = left;
                r->right = right;
            }
        }
        return root;
    }
};