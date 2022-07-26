/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
        
    Node* flatten(Node* head) {
       if(head==NULL){
           return NULL;
       }
        Node* p = head;
        while(p->child ==NULL){
            cout<<p->val<<endl;
            p=p->next;
            if(p == NULL){
                return head;
            }
        }
        Node* childtonext = flatten(p->child);
        cout<<childtonext->val<<endl;
        Node* afterchild = p->next;
        p->next= childtonext;
        childtonext->prev= p;
        
        Node* q = childtonext;
        while(q->next != NULL){
            q=q->next;
        }
       
        if(afterchild){
        afterchild->prev = q;
         q->next= afterchild;
        }
        else{
            q->next = NULL;
        }
        
        p->child = NULL;
        
        return head;
    }
};