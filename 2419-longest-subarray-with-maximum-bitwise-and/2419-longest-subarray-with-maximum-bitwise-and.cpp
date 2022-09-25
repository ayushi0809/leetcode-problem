class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        
        for(auto num : nums){
            maxi = max(maxi,num);
        }
       vector<int>v;
        int n = nums.size();
        int count =1;
        int ans =1;
        for(int i =0; i<n; i++){
            if(nums[i]==maxi){
               //cout<<i<<endl;
            v.push_back(i);
            }
        }
        int index = v[0];
        for(int i =1; i<v.size();i++){
            if(v[i]-index==1){
               
                count++;
                index = v[i];
            }
            else{
                cout<<v[i]<<endl;
                cout<<index<<endl;
                ans = max(ans,count);
                index = v[i];
                count = 1;
            }
        }
       
         ans = max(ans,count);
        return ans;
    }
       
};