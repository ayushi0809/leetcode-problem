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
    int length(ListNode* head){
        ListNode* p = head;
        int count=0;
        while(p!=NULL){
            count++;
            p=p->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x = length(head)-n;
        ListNode* p = NULL;
        ListNode* q = head;
        if(x == 0){
            head = head->next;
            delete q;
            return head;
        }
        for(int i=0;i<x;i++){
            p=q;
            q=q->next;
        }
        p->next=q->next;
        delete q;
        return head;
    }
};