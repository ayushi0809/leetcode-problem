class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        if(strs.size()==0){
            return {{""}};
        }
        if(strs.size()==1){
            return {{strs[0]}};
        }
        //sort(strs.begin(),strs.end());
        unordered_map<string,vector<string>>m;
        for(int i =0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
           // cout<<strs[i]<<endl;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
        
    }
};