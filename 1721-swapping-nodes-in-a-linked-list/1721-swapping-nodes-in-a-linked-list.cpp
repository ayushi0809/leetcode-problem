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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* p = head;
        for(int i=0; i<k-1 && p != NULL; i++){
            p=p->next;
        }
        ListNode* slow = head;
        ListNode* fast = p;
        while(fast != nullptr && fast-> next != nullptr){
            slow= slow->next;
            fast = fast->next;
        }
        swap(p->val, slow->val);
        return head;
    }
};