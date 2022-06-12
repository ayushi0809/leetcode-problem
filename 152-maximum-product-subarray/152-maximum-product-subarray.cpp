class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int s=1;
        int m = nums[0];
        
    
        for(int i =0; i<nums.size(); i++){
            s=s*nums[i];
            m = max(m,s);
            if( s==0 ){
                s=1;
            }
           
        }
        s=1;
        for(int i = nums.size()-1; i>=0; i--){
            s=s*nums[i];
            m = max(m,s);
            if(s==0){
                s=1;
            }
        }
        return m;
        
    }
};