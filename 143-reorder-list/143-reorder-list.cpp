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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return ;
        stack<ListNode*>st;
        ListNode* p = head;
        while(p != NULL){
            st.push(p);
            p=p->next;
        }
        p=head;
        ListNode* prev = st.top();
        ListNode* curr;
        while(p->next != NULL && p->next->next != NULL){
           curr = prev;
            cout<<curr->val<<endl;
            st.pop();
           prev = st.top();
            curr->next = p->next;
            p->next= curr;
            prev->next= NULL;
            p=p->next->next;
        }
        
    }
};