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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        int q =   (l1->val+l2->val)/10;
        l3->val = (l1->val+l2->val)%10;
        l3->next = nullptr;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* x = l3;
        while(l1 != nullptr && l2 != nullptr ){
            ListNode *p = new ListNode();
            p->val = (q+l1->val+ l2->val)%10;
            q = (q+l1->val+ l2->val)/10;
            x->next = p;
            p->next =NULL; 
            x =p;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            ListNode *p = new ListNode();
             p->val = (q+l1->val)%10;
            q = (q+l1->val)/10;
            x->next = p;
             p->next =nullptr; 
             x =p;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            ListNode *p = new ListNode();
             p->val = (q+l2->val)%10;
             q = (q+l2->val)/10;
             x->next = p;
             p->next =nullptr; 
             x =p;
            l2 = l2->next;
        }
        if(q != 0){
            ListNode *p = new ListNode();
            p->val = q;
            p->next = nullptr;
            x->next =p;
            x=p;
            
        }
        return l3;
    }
};