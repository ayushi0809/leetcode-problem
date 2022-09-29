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
    bool isEvenOddTree(TreeNode* root) {
        if(root->val%2==0){
            return false;
        }
        queue<TreeNode*>q;
        
        q.push(root);
        int level =0;
        
        while(!q.empty()){
            int s = q.size();
            int prev;
            if(level%2==0){
                prev=INT_MIN;
            }
            else{
                prev=INT_MAX;
            }
            
            while(s){
                TreeNode* x = q.front();
                q.pop();
                if(level%2==0){
                    if(x->val%2 == 0 || prev >= x->val){
                        return false;
                    }
                    else{
                        prev = x->val;
                    }
                }
                else{
                    if(x->val%2 == 1 || prev<=x->val){
                        return false;
                    }
                    else{
                        prev = x->val;
                    }
                    
                }
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
                s--;
            }
            level++;
        }
        return true;
    }
};