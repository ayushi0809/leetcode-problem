/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        unordered_map<ListNode*, int>m;
        if(!head || !head->next){
            return nullptr;
        }
       while(p){
            if(m.find(p->next) != m.end()){
                auto it = m.find(p->next);
                return it->first;
            }
            else{
            m.insert({p,p->val});
            }
           p=p->next;
       }
           
       // p->next = nullptr;
       // cout<<p->val<<endl;
       
            return nullptr;
        
        
    }
};