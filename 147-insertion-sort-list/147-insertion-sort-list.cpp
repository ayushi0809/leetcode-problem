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
    ListNode* f(ListNode* sorted, ListNode* q){
       
        q->next = NULL;
        // cout<<q->val<<endl;
        if(sorted == NULL){
            //cout<<"fist"<<endl;
            sorted = q;
            return sorted;
        }
        else if(sorted->val >= q->val){
            q->next = sorted;
            sorted = q;
            return sorted;
        }
            ListNode* prev = NULL;
            ListNode* x = sorted;
            while(x && x->val <q->val){
                prev = x;
                x=x->next;
            }
        cout<<prev->val<<endl;
            q->next = prev->next;
            prev->next = q;
        
        return sorted;
    }
    ListNode* insertionSortList(ListNode* head) {
         if(!head || !head->next)
            return head;
        ListNode* sorted = NULL;
        ListNode* p = head;
        ListNode* q = NULL;
        while(p != NULL){
            cout<<p->val<<endl;
            q=p;
            //q->next = NULL;
            p=p->next;
           sorted =  f(sorted, q);
            
            
        }
        return sorted;
    }
};