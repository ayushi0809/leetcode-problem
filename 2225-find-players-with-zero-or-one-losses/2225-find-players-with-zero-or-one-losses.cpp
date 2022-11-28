class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        unordered_set<int>st;
        for(auto it : matches){
            st.insert(it[0]);
            st.insert(it[1]);
            m1[it[0]]++;
            m2[it[1]]++;
        }
        vector<vector<int>>ans(2);
        for(auto it = st.begin(); it != st.end(); it++){
            if(m2[*it]==0){
                ans[0].push_back(*it);
            }
            if(m2[*it]==1){
                ans[1].push_back(*it);
            }
        }
        sort(ans[0].begin(), ans[0].end());
         sort(ans[1].begin(), ans[1].end());
        return ans;
        
        
        
    }
};