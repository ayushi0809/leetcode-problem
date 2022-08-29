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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = NULL;
        ListNode* q = list1;
        int count =0;
        while(q != NULL){
            if(count==a){
                break;
            }
            count++;
            p=q;
            q=q->next;
        }
        ListNode* r = list1;
        ListNode* x = list1->next;
         count =0;
        while(r != NULL){
            if(count == b){
                break;
            }
            count++;
            r=x;
            x=x->next;
        }
    ListNode* c = list2;
        while(c->next != NULL){
            c=c->next;
        }
        cout<<p->val<<" "<<x->val<<" "<<c->val<<endl;
        
        p->next = list2;
        c->next = x;
        
        return list1;
    }
};