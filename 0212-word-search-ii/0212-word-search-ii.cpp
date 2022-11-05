struct Node{
    Node* link[26];
    bool flag = false;
    
    bool containskey(char ch){
        return (link[ch-'a'] != NULL);
    }
    
    Node* get(char ch){
        return link[ch-'a'];
    }
    
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }
    
    void setend(){
        flag = true;
    }
    
    bool end(){
        return flag;
    }
    
    
};

class Trie {
   
    public:
     Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i =0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
        }
        node->setend();
        //cout<<node->flag<<endl;
    }
};
class Solution {
    int m,n;
    set<string>ans;
    void dfs(int r, int c, vector<vector<bool>> &vis, vector<vector<char>>& board, Node* node, string w){
       
        if(r<0 || r>=n || c<0 || c>=m){
            return;
        }
       // cout<<node->end()<<endl;
        node=node->get(board[r][c]);
        if( vis[r][c] == true || !node){
            return;
        }
        
        w=w+board[r][c];
        if(node->flag){
            ans.insert(w);
           // return;
        }
       // cout<<w<<endl;
        vis[r][c] = true;
        dfs(r+1, c,vis,board,node,w );
        dfs(r-1,c,vis,board,node,w);
        dfs(r,c+1,vis,board,node,w);
        dfs(r,c-1,vis,board,node,w);
        vis[r][c] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        n = board.size();
        m = board[0].size();
        for(auto s : words){
            t.insert(s);
        }
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        Node* node = t.root;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                dfs(i,j,vis,board,node,"");
            }
        }
        vector<string>res(ans.begin(), ans.end());
        
        return res;
        
    }
};