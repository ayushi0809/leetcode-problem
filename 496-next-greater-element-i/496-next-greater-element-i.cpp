class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(int i =0; i<nums2.size(); i++){
            m[nums2[i]] = i;
        }
        vector<int>ans(nums1.size(),-1);
        for(int i =0; i<nums1.size(); i++){
            auto it = m.find(nums1[i]);
            for(int j = it->second+1; j<nums2.size(); j++){
                if(nums2[j]>nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};