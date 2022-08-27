class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto a : nums){
            maxi = max(a,maxi);
            mini = min(a,mini);
        }
        //cout<<maxi-mini<<endl;
        vector<int>v(maxi-mini+1,0);
        
        for(auto a : nums){
            //cout<<a-mini<<endl;
            v[a-mini] =  v[a-mini] +1;
        }
        for(int i =1; i<v.size(); i++){
         v[i] = v[i]+v[i-1];   
        }
        int n = nums.size();
        vector<int>ans(n);
        for(int i = n-1; i>=0; i--){
            cout<<nums[i]-mini<<endl;
            int index = v[nums[i]-mini]-1;
            v[nums[i]-mini]--;
            ans[index] = nums[i];
        }
        
        return ans;
    }
};