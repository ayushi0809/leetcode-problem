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
    int getDecimalValue(ListNode* head) {
        string s;
        while(head != NULL){
            s=s+to_string(head->val);
            head=head->next;
        }
        int n = s.size();
        int i =0;
        int sum =0;
        while(n){
           sum = sum + (s[n-1]-'0')*pow(2,i);
            i++;
            n--;
        }
        return sum;
    }
};