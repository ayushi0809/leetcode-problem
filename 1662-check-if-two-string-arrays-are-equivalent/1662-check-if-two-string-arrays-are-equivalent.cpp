class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s = "";
        string s1 = "";
        
        for(auto a: word1){
            s=s+a;
        }
        
        for(auto a: word2){
            s1=s1+a;
        }
        
        return s == s1;
    }
};