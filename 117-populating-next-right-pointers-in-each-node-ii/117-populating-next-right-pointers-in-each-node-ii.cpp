/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
         Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node*>q;
        q.push(root);
        while(q.empty() == false){
            int s = q.size();
            for(int i = 0; i<s; i++){
                Node* x = q.front();
                q.pop();
                if(i+1 ==s){
                    x->next = NULL;
                }
                if(i+1 != s){
                    x->next = q.front();
                }
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
        }
        return root;
    }
};