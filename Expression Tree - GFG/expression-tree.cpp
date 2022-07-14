// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



 // } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

class Solution{
  public:
    /*You are required to complete below method */
    vector<string> s;
    void postorder(node* root){
         if(root != NULL){
            postorder(root->left);
            postorder(root->right);
            
            s.push_back(root->data);
        }
    }
    int evalTree(node* root) {
        // Your code here
        if(!root)
        return 0;
        if(!root->left && !root->right)
        return (stoi(root->data));
        int l = evalTree(root->left);
        int r = evalTree(root->right);
        
        if(root->data == "+")
        return l+r;
        else if(root->data=="-")
        return l-r;
        else if(root->data == "*")
        return l*r;
        else
        return l/r;
        // stack<int>st;
        // postorder(root);
        // //cout<<s<<endl;
        // for(auto x : s){
        //     if(x != "+" && x != "-" && x != "*" && x != "/"){
        //         //cout<<x-'0'<<endl;
        //         st.push(stoi(x));
        //     }
        //     else{
        //         int r = st.top();
        //         st.pop();
        //         int l = st.top();
        //         st.pop();
        //         if(x=="+"){
        //             st.push(l+r);
        //         }
        //         else if(x=="-"){
        //             st.push(l-r);
        //         }
        //         else if(x=="*"){
        //             st.push(l*r);
        //         }
        //         else{
        //             st.push(l/r);
        //         }
        //     }
        // }
        // return st.top();
       
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}
  // } Driver Code Ends