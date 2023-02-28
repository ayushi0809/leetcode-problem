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
    string duplicate(TreeNode* root, unordered_map<string,int> &m, vector<TreeNode*>&v){
        if(root == NULL)
            return "";
        string l = duplicate(root->left,m,v);
        string r = duplicate(root->right,m,v);
        
        string value = l+'-'+r+'-'+to_string(root->val);
        cout<<value<<endl;
        if(m.find(value) != m.end()){
            if(m[value]==1){
            v.push_back(root);
            }
            m[value]++;
        }
        else{
            m[value] = 1;
        }
        
        return value;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>m;
        vector<TreeNode*>v;
        duplicate(root,m,v);
        
        
        return v;
        
        
        
    }
};