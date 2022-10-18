class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long>v(n,0);
        for(int i =0; i<n; i++){
            v[edges[i]] = v[edges[i]]+i;
        }
        
        long maxi =LONG_MIN;
        int ans;
        
        for(int i =0;i<n; i++){
            if(v[i]>maxi){
                ans =i;
                maxi = v[i];
            }
        }
        
        return ans;
        
    }
};