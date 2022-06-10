class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>m;
        int n = s.size();
        int res = 0;
        int l =0;
        //bool f = false;
        for(int i =0; i<n; i++){
                //cout<<s[i]<<endl;
               while(m.find(s[i]) != m.end()){
                   m.erase(s[l]);
                   l = l+1;
               }
            
             m.insert({s[i], i});
            res = max(res, i-l+1);
        }
        
       
        return res;     
        
        
    }
};