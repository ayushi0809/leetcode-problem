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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        
        q.push({root, 0});
        int m = 0;
        long long f;
        long long l;
        while(!q.empty()){
            int s = q.size();
            int i =0;
            int st = s;
            
            
            while(s){
             auto a = q.front(); 
                //cout<<s<<" "<<a.first->val<<" "<<a.second<<endl;
            q.pop();
            if(i ==0){
                f = a.second;
            }
                if(i==st-1){
                    l = a.second;
                }
            if(a.first->left){
                q.push({a.first->left , 2*(a.second-f)+1});
            }
                if(a.first->right){
                q.push({a.first->right , 2*(a.second-f)+2});
            }
                i++;
                s--;
            }
            int ans = (int)(l-f);
            m = max(m, ans);
        }
        return m+1;
    }
};