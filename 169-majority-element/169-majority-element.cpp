class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
		int can = 0;
		int n = nums.size();
		for(int i=0;i<n;i++){
			if(cnt == 0){
				can = nums[i];
				++cnt;
			}
			else{
				if(nums[i] == can)++cnt;
				else --cnt;
			}
		}
		return can;
    }
};