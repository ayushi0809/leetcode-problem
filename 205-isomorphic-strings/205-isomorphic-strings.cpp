class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m;
        unordered_map<char,char>um;
        for(int i =0; i<s.size(); i++){
            char ch1 = s[i];
            char ch2 = t[i];
            if(m.find(ch1)==m.end()){
                m[ch1]=ch2;
            }
             if(um.find(ch2)==um.end()){
                um[ch2]=ch1;
            }
            if(m[ch1] != ch2 || um[ch2] != ch1)
                return false;
        }
        return true;
    }
};