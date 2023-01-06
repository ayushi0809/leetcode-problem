class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
         int n = points.size();
        stack<pair<int,int>>st;
        int x = 0;
        st.push({points[0][0], points[0][1]});
        for(int i = 1; i< n; i++){
            auto it = st.top();
            if(it.second>=points[i][0]){
                st.pop();
                st.push({it.first, min(it.second,points[i][1])});
            }
            else{
                st.push({points[i][0],points[i][1]});
                
            }
        }
        
        int ans = st.size();
        
        return ans;
        
        
        
    }
};