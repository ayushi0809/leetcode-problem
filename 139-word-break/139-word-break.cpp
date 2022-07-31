struct Node{
   Node* links[26];
    bool flag = false;
    
    bool containskey(char ch){
        return (links[ch-'a'] != NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void setend(){
        flag = true;
    }
};
class Trie{
    private:
        Node* root;
    public:
        Trie(){
           root = new Node(); 
        }
    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                node->put(word[i], new Node());
            }
            node= node->get(word[i]);
        }
        node->setend();
    }
    bool found(string &s, int idx, vector<bool> &visited){
            Node *node = root;
            if (idx == s.size() || visited[idx]) return idx == s.size();
            visited[idx] = true;
            for (int j = idx; j < s.size() && node->containskey(s[j]); j++) {
                    node = node->get(s[j]);
                    if (node->flag && found(s, j + 1, visited)) return true;  
            }  
            return false;
        }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* obj = new Trie();
        for(int i=0; i<wordDict.size(); i++){
            obj->insert(wordDict[i]);
        }
        vector<bool>visited(s.size());
        return obj->found(s,0,visited);
    }
};