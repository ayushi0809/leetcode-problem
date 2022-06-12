class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int>m;
        int n = nums.size();
        int res = 0;
        int l =0;
        int s =0;
        //bool f = false;
        for(int i =0; i<n; i++){
                //cout<<s[i]<<endl;
               while(m.find(nums[i]) != m.end()){
                   s=s-nums[l];
                   m.erase(nums[l]);
                   l = l+1;
                   
               }
            s=s+nums[i];
             m.insert({nums[i], i});
            res=max(res,s);
        }
        
       
        return res;
        
    }
};