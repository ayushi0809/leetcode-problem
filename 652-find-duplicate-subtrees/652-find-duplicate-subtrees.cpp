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
    string f(TreeNode* root, unordered_map<string, int>&m, vector<TreeNode*>&v){
        if(root == NULL)
            return "";
        string l = f(root->left, m,v);
        string r = f(root->right,m,v);
        string value = l+"-"+r+"-"+to_string(root->val);
        if(m[value]==1){
            m[value]++;
            v.push_back(root);
        }
        else{
            m[value]++;
        }
        return value;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int>m;
        vector<TreeNode*>v;
        f(root, m,v);
        for(auto it = m.begin(); it != m.end(); it++){
            cout<<it->first<<endl;
        }
        
        return v;
    }
};