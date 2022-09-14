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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0; i<lists.size(); i++){
            ListNode* head = lists[i];
            
            while(head != NULL){
                pq.push(head->val);
                head=head->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while(!pq.empty()){
            p->next = new ListNode(pq.top());
            pq.pop();
            p=p->next;
        }
        
        return dummy->next;
    }
};