/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        unordered_map<Node*,Node*>m;
        Node* p = new Node(head->val);
       // m.insert(head,p);
        m[head] = p;
        Node* q = p;
        while(head != NULL){
            if(head->next ){
                if(m.find(head->next) == m.end()){
                     Node* x = new Node(head->next->val);
                    // m.insert(head->next, x);
                    m[head->next] = x;
                     q->next = x;
                }
                if(m.find(head->next) != m.end()){
                    q->next = m[head->next];
                }
            }
            if(head->random){
                if(m.find(head->random) == m.end()){
                     Node* x = new Node(head->random->val);
                     m[head->random] =  x;
                     q->random = x;
                }
                if(m.find(head->random) != m.end()){
                    q->random = m[head->random];
                }
            }
            q=q->next;
            head=head->next;
               
            
        }
        return p;
        
    }
};