class Solution {
    struct Node{
    Node* links[26];
    bool flag=false;
   int count =0;
    
    bool containskey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag = true;
    }
    void inceremnt(){
        count=count+1;
    }
};
public:
    Node* root = new Node();
    void insert(string word) {
        Node* node = root;
        for(int i =0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                node->put(word[i], new Node());
               
            }
            node = node->get(word[i]);
            node->inceremnt();
        }
        node->setend();
    }
    int search(string word, int c) {
        Node* node = root;
        for(int i =0; i<word.size(); i++){
           node =  node->get(word[i]);
             c=c+node->count;
        }
        return c;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int>v(n);
        for(int i =0; i<n; i++){
            insert(words[i]);
        }
        for(int i =0; i<n; i++){
            v[i] = search(words[i],0);
        }
        
        return v;
        
    }
};