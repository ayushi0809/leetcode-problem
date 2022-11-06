class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans;
        
        int i =0;
        int j =0;
        
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
            
        }
        
        while(i<n){
             ans.push_back(nums1[i]);
                i++;
        }
        while(j<m){
             ans.push_back(nums2[j]);
                j++;
        }
        int s = ans.size();
        float d;
        if(s%2==0){
            d = (ans[s/2]+ans[(s/2)-1])/2.0;
        }
        else{
            d = ans[s/2];
        }
        
        return d;
        
    }
};