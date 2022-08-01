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
    unordered_map<TreeNode*,int>ms;
    void dfs(TreeNode* root){
        if(root == NULL)
            return;
        else if(!root->left && !root->right){
            ms[root] = root->val;
        }
        else if(!root->left){
            dfs(root->right);
            ms[root] = root->val+ms[root->right]; 
        }
        else if(!root->right){
            dfs(root->left);
            ms[root] = root->val+ms[root->left]; 
        }
        else {
            dfs(root->left);
            dfs(root->right);
            ms[root] = ms[root->left]+ms[root->right]+root->val;
        }
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        unordered_map<int,int>m;
        vector<int>v;
        for(auto it = ms.begin(); it != ms.end(); it++){
            m[it->second]++;
        }
        int freq = INT_MIN;
        for(auto it = m.begin(); it != m.end(); it++){
           freq = max(freq,it->second);
        }
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second==freq){
                v.push_back(it->first);
            }
        }
        return v;
    }
};