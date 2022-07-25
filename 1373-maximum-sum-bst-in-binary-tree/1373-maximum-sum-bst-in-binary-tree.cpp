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
    unordered_map<TreeNode*, int>subtreesum;
    unordered_map<TreeNode*, bool>isbst;
    unordered_map<TreeNode*, int>minValue;
    unordered_map<TreeNode*, int>maxValue;
    
    void dfs(TreeNode* root){
        if(root == NULL)
            return;
        else if(!root->left && !root->right){
            subtreesum[root] = root->val;
            isbst[root] = true;
            minValue[root] = root->val;
            maxValue[root] = root->val;
        }
        else if(root->left == NULL){
            dfs(root->right);
            subtreesum[root] = root->val+subtreesum[root->right];
            minValue[root] = min(root->val, minValue[root->right]);
            maxValue[root]= max(root->val, maxValue[root->right]);
            if(isbst[root->right]==true && minValue[root->right]>root->val){
                isbst[root]= true;
            }
            else{
                isbst[root]=false;
            }
        }
        else if(root->right == NULL){
            dfs(root->left);
            subtreesum[root] = root->val+subtreesum[root->left];
            minValue[root] = min(root->val, minValue[root->left]);
            maxValue[root]= max(root->val, maxValue[root->left]);
             if(isbst[root->left]==true && maxValue[root->left]<root->val){
                isbst[root]= true;
            }
            else{
                isbst[root]=false;
            }
        }
        else{
            dfs(root->right);
            dfs(root->left);
            subtreesum[root] = root->val+subtreesum[root->right]+ subtreesum[root->left];
            minValue[root] = min(root->val, min(minValue[root->left] , minValue[root->right]));
            maxValue[root] = max(root->val, max(maxValue[root->left], maxValue[root->right]));
            if(isbst[root->left]==true && isbst[root->right]== true && minValue[root->right]>root->val && maxValue[root->left]<root->val){
                isbst[root]=true;
            }
            else{
                isbst[root]=false;
            }
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root);
        for(auto it = subtreesum.begin(); it != subtreesum.end(); it++){
            if(isbst[it->first] && it->second>=0){
                ans = max(ans, it->second);
            }
        }
        if(ans == INT_MIN)
            return 0;
        return ans;
        
    }
};