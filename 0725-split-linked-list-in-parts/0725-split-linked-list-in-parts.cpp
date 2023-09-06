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
        int count=0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p = head;
        int n = len(p);
        p=head;
        ListNode* q = NULL;
        int j=0;
        int i =0;
        vector<ListNode*>v(k);
        for(i =0; i<n%k; i++){
            ListNode* r = p;
            j=0;
            while(j<=n/k ){
                q=p;
                
                p=p->next;
                
                j++;
            }
            q->next= NULL;
            v[i] = r;
            
        }
        while(p){
            ListNode* r = p;
            j=0;
            while(j<n/k ){
                q=p;
                
                p=p->next;
                
                j++;
            }
            q->next= NULL;
            v[i] = r;
            i++;
        }
        return v;
    }
};