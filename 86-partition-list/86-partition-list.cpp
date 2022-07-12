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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p = new ListNode();
        ListNode* small =p;
        ListNode* q = new ListNode();
        ListNode* big = q;
        ListNode* curr = head;
        while(curr != NULL){
            if(curr->val<x){
                ListNode* x = new ListNode(curr->val);
                small->next =x;
                small = small->next;
            }
            else{
                ListNode* x = new ListNode(curr->val);
                big->next =x;
                big = big->next;
            }
            curr=curr->next;
        }
       small->next= q->next;
        return p->next;
    }
};