/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>trav;
        if(root == NULL){
            return trav;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int s = q.size();
            while(s){
                 Node* x  = q.front();
                cout<<x->val<<endl;
                q.pop();
                v.push_back(x->val);
                for(Node* ch : x->children){
                    q.push(ch);
                    
                }
                s--;
            }
            trav.push_back(v);
            v.clear();
        }
        return trav;
    }
};