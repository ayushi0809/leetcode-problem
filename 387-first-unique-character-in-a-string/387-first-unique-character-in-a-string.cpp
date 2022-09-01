class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        for(auto a : s){
            m[a]++;
        }
        
        for(int i =0; i<s.size(); i++){
            if(m.find(s[i])->second == 1){
                return i;
            }
        }
        return -1;
    }
};