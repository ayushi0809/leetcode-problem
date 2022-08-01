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
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        ListNode* ans ;
        if(a->val<=b->val){
             ans = a;
            ans->next = merge(a->next,b);
            
        }
        else{
            ans = b;
            ans->next = merge(a,b->next);
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* p = NULL;
        for(int i=0; i<lists.size(); i++){
            p = merge(p,lists[i]);
        }
        return p;
    }
};