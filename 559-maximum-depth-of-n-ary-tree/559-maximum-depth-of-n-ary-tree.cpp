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
    int ans = 0;
    void dfs(Node* root, int d){
        if(root == NULL){
            return;
        }
        for(auto it : root->children){
            dfs(it,d+1);
        }
        ans = max(ans,d);
    }
    int maxDepth(Node* root) {
        dfs(root,1);
        return ans;
    }
};