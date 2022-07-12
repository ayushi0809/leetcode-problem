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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* nex = head;
        while(head != NULL){
            nex = head->next;
            head->next=prev;
            prev=head;
            head = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       //   vector<int>v;
       //  while(head != NULL){
       //     v.push_back(head->val);
       //      head = head->next;
       //  }
       //  int i  =0;
       //  int j = v.size()-1;
       // while(i<j){
       //     if(v[i] != v[j])
       //         return false;
       //     else{
       //         i++;
       //         j--;
       //     }
       // }
       //  return true;
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow != NULL){
            if(slow->val != head->val)
                return false;
            else{
                head=head->next;
                slow = slow->next;
            }
        }
        return true;
    }
};