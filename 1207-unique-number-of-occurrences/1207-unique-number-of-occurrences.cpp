class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto it : arr){
            m[it]++;
        }
        unordered_set<int>st;
        for(auto it = m.begin(); it != m.end(); it++){
            st.insert(it->second);
        }
        
        return m.size()==st.size();
        
    }
};