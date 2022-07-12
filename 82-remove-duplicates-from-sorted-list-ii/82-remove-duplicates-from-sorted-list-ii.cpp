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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = new ListNode();
        ListNode* q =p;
        ListNode* r = head;
        while(r != NULL){
            if(r->next==NULL){
                ListNode* x = new ListNode(r->val);
                q->next = x;
                q=q->next;
                r=r->next;
            }
            else if(r->val != r->next->val){
                ListNode* x = new ListNode(r->val);
                q->next = x;
                q=q->next;
                r=r->next;
            }
            else{
            while( r->next != NULL && r->val == r->next->val){
                
                r=r->next;
            }
                
                r=r->next;
            }
           
        }
        return p->next;
    }
};