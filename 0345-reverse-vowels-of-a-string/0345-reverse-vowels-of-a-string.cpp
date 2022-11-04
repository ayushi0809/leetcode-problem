class Solution {
public:
    string reverseVowels(string s) {
        vector<pair<char,int>>v;
        
        for(int i =0; i<s.size(); i++){
            //char a = s[i];
            if(s[i]=='a' || s[i]== 'e' || s[i]== 'i' || s[i]=='o' || s[i]=='u' || s[i]== 'A' || s[i]== 'E' || s[i] == 'I' || s[i]== 'O' || s[i]== 'U'){
                v.push_back({s[i], i});
        }
        }
        
        int l =0; 
        int r = v.size()-1;
        
        while(l<=r){
            auto it = v[l];
            auto it2 = v[r];
            s[it.second] = it2.first;
            s[it2.second] = it.first;
            l++;
            r--;
        }
        
        return s;
        
    }
};