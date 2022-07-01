class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>pattern;
        vector<int>v;
        int start =0;
        int flag =0;
        int k = p.size();
        for(auto x : p){
            
                pattern[x]++;
            
        }
        unordered_map<char,int>str;
        for(int i =0;i<s.size();i++){
            str[s[i]]++;
            if(i+1>=k){
                for(auto it = pattern.begin(); it!=pattern.end();it++){
                    if(str.find(it->first) != str.end() && str.find(it->first)->second == it->second){
                        flag =1;
                    }
                    else{
                        flag =0;
                        break;
                    }
                }
                if(flag==1){
                    v.push_back(start);
                }
                str[s[start]]--;
                flag =0;
                start++;
            }
        }
        return v;
    }
};