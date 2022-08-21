class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count =0;
        for(auto a : nums){
            if(a==0){
                return 0;
            }
            if(a<0){
                count++;
            }
        }
        if(count%2==0){
            return 1;
        }
        return -1;
    }
};