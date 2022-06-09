/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        if(!head || !head->next){
            return NULL;
        }
        while(q && q->next){
            q= q->next->next;
            p=p->next;
            if(p==q){
                break;
            }
        }
        if(p!=q){
            return NULL;
        }
        p =head;
        while(p != q){
            p=p->next;
            q=q->next;
        }
        return p;
    }
};