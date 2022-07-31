class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortcol);
        int n = intervals.size();
        stack<pair<int,int>>st;
        int x = 0;
        st.push({intervals[0][0], intervals[0][1]});
        for(int i = 1; i< n; i++){
            auto it = st.top();
            if(it.second>=intervals[i][0]){
                st.pop();
                st.push({it.first, max(it.second,intervals[i][1])});
            }
            else{
                st.push({intervals[i][0],intervals[i][1]});
                
            }
        }
     vector<vector<int>>nums(st.size(), vector<int> (2));
        while(st.size()){
            auto it = st.top();
            nums[x][0]= it.first;
            nums[x][1]=it.second;
            x++;
            st.pop();
        }
        return nums;
    }
};