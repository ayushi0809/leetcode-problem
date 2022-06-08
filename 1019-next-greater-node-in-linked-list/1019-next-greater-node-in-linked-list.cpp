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
    int len(ListNode* p){
        int l =0;
        while(p){
            p=p->next;
            l++;
        }
        return l;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* p = head;
        vector<int>v(len(p));
        stack<pair<int,int>>st;
        p =head;
        int i =0;
        while(p){
            while(!st.empty() && st.top().first<p->val){
                v[st.top().second] = p->val;
                st.pop();
            }
            st.push({p->val, i});
            p=p->next;
            i++;
        }
        while(!st.empty()){
            v[st.top().second]=0;
            st.pop();
        }
        return v;
    }
};