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
private:
    int getLength(ListNode* head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            ++cnt;
        }
        return cnt;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr;
        ListNode* nex;
        
        int len = getLength(head);
        
        while(len >= k) {
            curr = prev->next;
            nex = curr->next;
            
            for(int i=1; i<k; ++i) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            
            prev = curr;
            len -= k;
        }
        
        return dummy->next;
        
    }
};