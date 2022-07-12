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
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sort(ListNode* a, ListNode* b){
       if(!a)return b;
        if(!b)return a;
        ListNode *ans;
        if(a->val<b->val){
            ans=a;
            ans->next=sort(a->next,b);
        }
        else
        {
            ans=b;
            ans->next=sort(a,b->next);
        }
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* mid  = findmid(head);
        ListNode* midNext = mid->next;
        mid->next = NULL;
        head = sortList(head);
        midNext = sortList(midNext);
        return sort(head, midNext);
        
    }
};