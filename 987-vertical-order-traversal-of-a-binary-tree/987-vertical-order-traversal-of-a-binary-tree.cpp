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
   
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //m[root] = 0;
        //dfs(root,0);
         map<int, vector<pair<int,int>>>m;
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root,{0, 0}});
        while(!q.empty()){
           // int s = q.size();
                auto it = q.front();
                q.pop();
                m[it.second.second].push_back({it.second.first , it.first->val});
                if(it.first->left){
                    q.push({it.first->left,{it.second.first+1, it.second.second-1}});
                }
                 if(it.first->right){
                    q.push({it.first->right,{it.second.first+1, it.second.second+1}});
                }
               
        }
        vector<vector<int>>ans;
        
        for(auto it : m){
            sort(it.second.begin(), it.second.end());
            vector<int>v;
            for(auto x : it.second){
                cout<<x.first<<" "<<x.second<<endl;
                v.push_back(x.second);
            }
            cout<<"next level"<<endl;
            ans.push_back(v);
        }
     return ans;   
    }
};