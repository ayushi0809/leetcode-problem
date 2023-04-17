class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>ans(n,false);
        int maxi = INT_MIN;
        for(auto it : candies){
            maxi = max(it,maxi);
        }
        for(int i =0; i<n; i++){
            ans[i] = candies[i]+extraCandies>=maxi ? true : false;
        }
        
        return ans;
        
    }
};