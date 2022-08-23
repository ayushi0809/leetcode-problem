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
    unordered_map<int,vector<int>>m;
    void dfs(TreeNode* root, TreeNode* parent){
        if(!root){
            return;
        }
        if(parent){
        m[root->val].push_back(parent->val);
        }
        if(root->left){
            m[root->val].push_back(root->left->val);
        }
        if(root->right){
            m[root->val].push_back(root->right->val);
        }
        dfs(root->left,root);
        dfs(root->right,root);
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, NULL);
        queue<pair<int,int>>q;
        unordered_map<int,bool>vis;
        vis[start] = true;
        for(auto a : m[start]){
            q.push({a,1});
            vis[a] = true;
        }
        int time = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            time = it.second;
            for(auto a : m[node]){
                if(!vis[a]){
                    q.push({a,time+1});
                    vis[a] = true;
                }
            }
        }
        return time;
    }
};