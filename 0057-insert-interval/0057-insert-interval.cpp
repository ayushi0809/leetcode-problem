class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int,int>>v;
        for(auto it : intervals){
            v.push_back({it[0], it[1]});
        }
        
            v.push_back({newInterval[0], newInterval[1]});
        
        sort(v.begin(),v.end());
        
        stack<pair<int,int>>st;
        st.push(v[0]);
        for(int i =1; i<v.size(); i++){
            auto it = v[i];
            auto it1 = st.top();
            if(it.first<=it1.second){
                st.pop();
                st.push({it1.first, max(it.second, it1.second)});
            }
            else{
                st.push({it.first,it.second});
            }
        }
        int n = st.size();
        vector<vector<int>>ans(n);
        while(!st.empty()){
            auto it = st.top();
            ans[n-1] = {it.first,it.second};
            st.pop();
            n--;
        }
        return ans;
    }
};