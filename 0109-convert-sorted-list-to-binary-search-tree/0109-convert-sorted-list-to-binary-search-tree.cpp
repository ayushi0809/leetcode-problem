/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* bst(vector<int> arr, int f, int l){
        if(f>l){
            return NULL;
        }
       
            struct TreeNode* root;
            int mid = (f+l)/2;
            root = new TreeNode(arr[mid]);
            root->left = bst(arr, f, mid-1);
            root->right = bst(arr, mid+1, l);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        struct TreeNode* root;
        struct ListNode* p = head;
        vector<int> arr;
        while(p){
            arr.push_back(p->val);
            p=p->next;
        }
        
        int l = arr.size();
        root = bst(arr, 0, l-1);
        return root;
    }
};