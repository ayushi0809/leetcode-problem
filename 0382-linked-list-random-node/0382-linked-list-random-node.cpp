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
    ListNode* p;
    vector<int>v;
    int s ;
    Solution(ListNode* head) {
        p = head;
        while(p != NULL){
            v.push_back(p->val);
            p=p->next;
        }
        s=v.size();
    }
    
    int getRandom() {
        int ind = (int)rand()%v.size();
        return v[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */