/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//     bool roottonode(TreeNode* root, TreeNode* p, vector<TreeNode*> &v){
//         if(root == NULL)
//             return false;
//         TreeNode* x = new TreeNode(root->val);
//        v.push_back(x);
//         if(root->val == p->val)
//             return true;
        
//         if(roottonode(root->left, p,v) || roottonode(root->right, p,v)){
           
//             return true;
//         }
//        v.pop_back();
//         return false;
//     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        vector<TreeNode*>v1;
//         vector<TreeNode*>v2;
//         roottonode(root,p,v1);
//         roottonode(root,q,v2);
//         int i=0;
//         int j =0;
//         while(i<v1.size() && j<v2.size() && v1[i]->val == v2[j]->val){
//             i++;
//             j++;
//         }
       
//         if(i==0)
//             return v1[i];
//         return v1[--i];
        if(root == NULL || root ==p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p,q);
        TreeNode* right = lowestCommonAncestor(root->right, p,q);
        
        if(left == NULL)
            return right;
        if(right==NULL)
            return left;
        return root;
    }
};