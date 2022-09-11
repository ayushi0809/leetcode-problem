class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int max_value = values[0];
        int ans = INT_MIN;
        
        for(int i =1; i<n; i++){
            ans = max(ans, max_value+values[i] - i);
            max_value = max(max_value, i+values[i]);
            
        }
        return ans;
        
    }
};