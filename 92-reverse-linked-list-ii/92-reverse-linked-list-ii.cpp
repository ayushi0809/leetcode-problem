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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int n = right-left+1;
        ListNode* dummy = new ListNode(0, head);
        ListNode* lp = dummy;
        ListNode* p = NULL;
        ListNode* c = head;
        while(left-1){
            lp=c;
            c=c->next;
            left--;
        }
        
       
        while(n){
            ListNode* temp = c->next;
            c->next = p;
            p=c;
            c=temp;
            n--;
        }
       
        lp->next->next = c;
        lp->next = p;
        cout<<lp->val<<endl;
        return dummy->next;
    }
};