class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>ms;
        unordered_map<char,int>mt;
        for(auto a : s){
            ms[a]++;
        }
        for(auto a : t){
            mt[a]++;
        }
        if(ms.size() != mt.size())
            return false;
        for(auto it = ms.begin(); it != ms.end(); it++){
            char a = it->first;
            int count = it->second;
            if(mt.find(a) == mt.end() || mt.find(a)->second != count){
                return false;
            }
        }
        return true;
    }
};