class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // int n = floor(nums.size()/3);
        // unordered_map<int,int>m;
        // vector<int>v;
        // for(auto x : nums){
        //     m[x]++;
        // }
        // for(auto it = m.begin(); it !=m.end();it++){
        //     if(it->second>n){
        //         v.push_back(it->first);
        //     }
        // }
        // return v;
        int nums1 =INT_MIN;
        int nums2 =INT_MIN;
        int count1 =0;
        int count2=0;
        int m = nums.size()/3;
        
        for(auto x:nums){
            if(x==nums1){
                count1= count1+1;
            }
            else if(x==nums2){
                count2=count2+1;
            }
            else if(count1==0){
                    nums1 =x;
                    count1=1;
                }
            else if(count2==0){
                    nums2=x;
                    count2=1;
                }
                else{
                    count1--;
                    count2--;
                }
            
        }
        count1 = 0, count2 =0;
        for(auto it : nums) if(it == nums1) count1++;
        for(auto it : nums) if(it == nums2) count2++;
        vector<int>ans;
        if(count1>m) ans.push_back(nums1);
        if(count2>m) ans.push_back(nums2);
        return ans;
    }
};