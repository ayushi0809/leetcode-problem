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
        int count = 0;
        while(head != nullptr){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* last = head;
        int l = len(node);
        if(head == nullptr || k==0 || k==l || head->next == nullptr || k%l==0)
            return head;
        
        int x = l - k%l;
        int t = k%l;
       while(x>1){
           last = last->next;
           x--;
       }
        ListNode* h = last->next;
        ListNode* curr = last;
        while(t>=1){
            curr= curr->next;
            t--;
        }
        curr->next = head;
        last->next = nullptr;
        head = h;
        return head;
    }
        
};