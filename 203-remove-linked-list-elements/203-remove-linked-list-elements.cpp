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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        
        ListNode* q = NULL;
        ListNode* p = head;
        
        while(p != NULL){
            
            if(p->val == val ){
                cout<<p->val<<endl;
                //ListNode* r = p;
                if(q){
                q->next = p->next;
                }
                //q=q->next;
                else{
                    head= head->next;
                }
                p=p->next;
                
               // delete r;
            }
            
            else{
            q=p;
            p=p->next;
            }
            
        }
        //cout<<head->val<<endl;
        //cout<<"hello"<<endl;
        if(head==NULL){
            return NULL;
        }
        return head;
    }
};