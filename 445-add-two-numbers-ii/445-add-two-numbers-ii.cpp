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
        stack<ListNode*>st1;
        ListNode* p = NULL;
        while(l1 != NULL){
            p=l1;
            //p->next = NULL;
            l1=l1->next;
            st1.push(p);
        }
        stack<ListNode*>st2;
        ListNode* q = NULL;
        while(l2 != NULL){
            q=l2;
            //q->next = NULL;
            l2=l2->next;
            st2.push(q);
        }
        stack<ListNode*>res;
        int carry = 0;
        int k;
        while(!st1.empty() && !st2.empty()){
            int value1 = st1.top()->val;
            int value2 = st2.top()->val;
            st1.pop();
            st2.pop();
            k = carry+value1+value2;
            cout<<value1<<" "<<value2<<endl;
            carry = k/10;
            ListNode* x = new ListNode(k%10);
            res.push(x);
        }
        while(!st1.empty()){
            if(carry !=0){
                k = carry+st1.top()->val;
                carry = k/10;
                ListNode* x = new ListNode(k%10);
                res.push(x);
            }
            else{
            res.push(st1.top());
           
            }
             st1.pop();
        }
        while(!st2.empty()){
            if(carry !=0){
                k = carry+st2.top()->val;
                carry = k/10;
                cout<<carry<<endl;
                ListNode* x = new ListNode(k%10);
                res.push(x);
            }
            else{
            res.push(st2.top());
            
            }
            st2.pop();
        }
        if(carry != 0){
            ListNode* x = new ListNode(carry);
            res.push(x);
        }
        ListNode* dummy = new ListNode(0);
        p=dummy;
        while(!res.empty()){
            p->next = res.top();
            res.pop();
            p=p->next;
        }
        return dummy->next;
    }
};