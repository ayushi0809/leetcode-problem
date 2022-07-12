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
    ListNode* sortList(ListNode* head) {
     vector<int>v;
        ListNode* q = head;
        while(q != NULL){
            v.push_back(q->val);
            q=q->next;
        }
        sort(v.begin(), v.end());
        ListNode* p = new ListNode();
        q=p;
        for(int i=0; i<v.size(); i++){
            ListNode* x = new ListNode(v[i]);
            q->next = x;
            q=q->next;
        }
        return p->next;
    }
};