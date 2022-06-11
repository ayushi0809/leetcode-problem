class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        cout<<i<<endl;
        if(i<0){
            reverse(nums.begin(), nums.end());
        }
        else{
        int n = nums.size()-1;
        while(n>=0){
            if(nums[n]>nums[i]){
                break;
            }
            n--;
        }
        
        swap(nums[i], nums[n]);
        reverse(nums.begin()+1+i, nums.end());
        }
    }
};