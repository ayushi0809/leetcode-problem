class Solution {
public:
   
    bool increasingTriplet(vector<int>& nums) {
        int f= INT_MAX;
        int s = INT_MAX;
       for(auto a : nums){
           if(a<=f){
               f=a;
           }
           else if(a<=s){
               s=a;
           }
           else
               return true;
       }
        return false;
    }
};