class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        for(int i =0; i<n; i++){
            nums.push_back(nums[i]);
        }
        vector<int>prefix(2*n+1);
        
        prefix[0] = nums[0];
        //cout<<nums.size()<<endl;
        for(int i =1; i< 2*n; i++){
            //cout<<i<<endl;
            prefix[i] = prefix[i-1]+nums[i];
        }
        deque<int>dq;
        dq.push_back(0);
        int ans = prefix[0];
        for(int j =1; j<2*n; j++){
            if(dq.front()<j-n)
                dq.pop_front();
            ans = max(ans, prefix[j]-prefix[dq.front()]);
            cout<<ans<<endl;
            while(!dq.empty() && prefix[j]<=prefix[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            
        }
        return ans;
    }
};