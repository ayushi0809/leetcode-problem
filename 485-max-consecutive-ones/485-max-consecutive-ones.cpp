class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int maxi = INT_MIN;
        int i =0;
        for( i =0; i<n; i++){
            if(nums[i] != 1){
                maxi = max(maxi, i-start);
                start = i+1;
            }
        }
        cout<<i<<endl;
        maxi  = max(maxi, i-start);
        return maxi;
        
    }
};