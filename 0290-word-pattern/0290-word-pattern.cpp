class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        unordered_map<string,char>m;
        stringstream str(s);
        string st;
        int i =0;
        int count=0;
        for(auto x :s){
            if(x == ' '){
                count++;
            }
        }
        if(count+1 != pattern.size())
            return false;
        while(getline(str,st,' ') && i<pattern.size()){
            if(mp.find(pattern[i]) == mp.end() && m.find(st) == m.end()){
                mp[pattern[i]] = st;
                m[st] = pattern[i];
            }
            else if(mp[pattern[i]] != st || m[st] != pattern[i]){
                return false;
            }
            i++;
        }
        
       
        return true;
        
    }
};