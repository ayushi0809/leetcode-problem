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
    int len(ListNode* head){
        int count =0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* prev1 = NULL;
        ListNode* curr1 = head;
         ListNode* prev2 = NULL;
        ListNode* curr2 = head;
        ListNode* p = head;
         int l = len(p);
        if(head == NULL || k == l-k+1 || head->next == NULL)
            return head;
        if(k==1 || k == l){
            while(curr1->next != NULL){
                prev1 =curr1;
                curr1 = curr1->next;
            }
            p = head;
            if(p==prev1){
                 curr1->next  = p;
                p->next= NULL;
            }
            else{
            curr1->next  = p->next;
            prev1->next = p;
            p->next = NULL;
            }
            head = curr1;
            return head;
            
        }
        int i =0;
        while(i<k-1){
            prev1= curr1;
            curr1=curr1->next;
            i++;
        }
       
        int j =0;
        while(j<l-k){
            prev2= curr2;
            curr2=curr2->next;
            j++;
        }
        
        
        //cout<<curr2->next->val<<endl;
         prev2->next = curr1;
         prev1->next = curr2;
        ListNode* q = curr1->next;
        curr1->next= curr2->next;
        curr2->next =q;
         //prev2->next = curr1;
        
        cout<<prev1->val<<curr1->val<<prev2->val<<curr2->val<<endl;
        return head;
    }
};