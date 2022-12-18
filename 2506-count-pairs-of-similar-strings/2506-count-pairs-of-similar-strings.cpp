class Solution {
public:
    int similarPairs(vector<string>& words) {
     map<set<char>,int>m;
        
        for(auto s : words){
            set<char>st;
            for(auto it : s)st.insert(it);
            
            m[st]++;
        }
        int count =0;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second>1){
                count = count + (it->second*(it->second-1))/2;
            }
        }
        
        return count;
    }
};