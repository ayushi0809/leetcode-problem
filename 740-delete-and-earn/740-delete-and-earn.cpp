class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int,int>m;
        for(auto a : nums){
            m[a]++;
        }
        unordered_set<int>st;
        for(auto a : nums){
            st.insert(a);
        }
        nums.clear();
        
        for(auto it = st.begin(); it != st.end(); it++){
            nums.push_back(*it);
        }
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),0);
        for(int i =0; i<nums.size(); i++){
            //cout<<nums[i]<<endl;
            int earning = nums[i]*m[nums[i]];
            //cout<<earning<<endl;
            if(i>0 && nums[i]-1 == nums[i-1]){
                if(i>1){
                dp[i] = max(earning+dp[i-2], dp[i-1]);
                }
                else{
                    dp[i] = max(earning,dp[i-1]);
                }
                cout<<"ho>"<<endl;
            }
            else{
                if(i>0){
                dp[i] = earning+dp[i-1];
                }
                else{
                    dp[i] = earning;
                }
                cout<<"hiihi"<<endl;
            }
        }
        return dp[nums.size()-1];
    }
};