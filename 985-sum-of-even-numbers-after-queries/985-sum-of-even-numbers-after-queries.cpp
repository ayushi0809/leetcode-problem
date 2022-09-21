class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum =0;
        for(int i =0; i<n; i++){
            if(nums[i]%2==0){
                sum = sum+nums[i];
            }
        }
        vector<int>ans(queries.size(),0);
        for(int i =0; i<queries.size(); i++){
            int val = queries[i][0];
            int index = queries[i][1];
            if(nums[index]%2==0){
                if((nums[index]+val)%2==0){
                    sum=sum+val;
                    ans[i] = sum;
                }
                else{
                    sum=sum-nums[index];
                    ans[i] =sum;
                }
            }
            else{
                if((nums[index]+val)%2==0){
                    sum=sum+nums[index]+val;
                }
                ans[i] = sum;
                
            }
            nums[index]=nums[index]+val;
            
        }
       return ans; 
    }
};