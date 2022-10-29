class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
     vector<pair<int,int>>v;
        for(int i =0; i<plantTime.size(); i++){
            v.push_back({growTime[i] , plantTime[i]});
        }
        
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        int ans = INT_MIN;
        int day =0;
        for(int i =0 ;i <v.size(); i++){
            day = day+v[i].second;
            ans = max(ans, day+v[i].first);
        }
        
        return ans;
    }
};