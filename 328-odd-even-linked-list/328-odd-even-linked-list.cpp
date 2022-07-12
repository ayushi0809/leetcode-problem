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
    
    ListNode* oddEvenList(ListNode* head) {
        ListNode* p = head;
        int count =0;
        if(head == NULL || head->next == NULL)
            return head;
        while(p->next != NULL){
            count++;
            p=p->next;
        }
        int  c=(count+1)/2;
        ListNode* q = head;
        while(c>0){
            p->next = q->next;
            q->next = p->next->next;
            p=p->next;
            p->next=NULL;
            q = q->next;
            c--;
        }
        return head;
    }
};