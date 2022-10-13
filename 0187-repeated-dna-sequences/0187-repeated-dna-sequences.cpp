class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        int start =0;
        unordered_map<string,int>m;
        vector<string>ans;
        string a = "";
        int i =0;
        for( i =0; i<n; i++){
            if(i-start+1 == 11){
                m[a]++;
                a.erase(0,1);
                start = start+1;
            }
             a=a+s[i];
        }
        if(i-start+1 == 11){
                m[a]++;
                a.erase(0,1);
                start = start+1;
            }
        for(auto it = m.begin() ; it != m.end(); it++){
            if(it->second>1){
                ans.push_back(it->first);
                
            }
        }
     return ans;   
    }
};