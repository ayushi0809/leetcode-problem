class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count= 0;
		int majority = 0;
		int n = nums.size();
		for(int i=0;i<n;i++){
			if(count == 0){
				majority = nums[i];
				count = count+1;
			}
			else{
				if(nums[i] == majority)count = count+1;
				else count = count-1;
			}
		}
		return majority;
    }
};