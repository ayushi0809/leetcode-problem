/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone;
    void dfs(Node* node, unordered_map<Node*, Node*>&m, Node* parent){
        Node* root = new Node(node->val);
        if(m.empty()){
            clone = root;
        }
        m.insert({node,root});
        if(parent != NULL){
            auto it = m.find(parent);
            it->second->neighbors.push_back(root);
        }
        for(Node* ch : node->neighbors){
            if(m.find(ch)==m.end()){
                dfs(ch,m,node);
            }
            else{
                auto it = m.find(ch);
                auto it2 = m.find(node);
                it2->second->neighbors.push_back(it->second);
            }
            
        }
        
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
       unordered_map<Node*, Node*>m;
        dfs(node, m, NULL);
        return clone;
    }
};