class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m =0;
        for(int i = n-1; i>=2; i--){
            int a = nums[i];
            int b = nums[i-1];
            int c = nums[i-2];
            if(a+b>c && b+c>a && c+a>b){
                m = max(m, a+b+c);
            }
        }
        return m;
    }
};