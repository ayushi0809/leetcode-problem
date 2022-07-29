class Solution {
public:
    bool f(string words, string pattern){
        unordered_map<char,char>m;
        unordered_map<char,char>um;
        for(int i =0; i<words.size(); i++){
            char ch1 = words[i];
            char ch2 = pattern[i];
            if(m.find(ch1)==m.end()){
                m[ch1]=ch2;
            }
            if(um.find(ch2)==um.end()){
                um[ch2] = ch1;
            }
            if(m[ch1] != ch2 || um[ch2] != ch1){
                //cout<<ch1<<" "<<ch2<<endl;
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>v;
        cout<<f("aqq", "abb")<<endl;
        for(auto a : words){
            if(f(a, pattern)){
                v.push_back(a);
            }
        }
        return v;
    }
};