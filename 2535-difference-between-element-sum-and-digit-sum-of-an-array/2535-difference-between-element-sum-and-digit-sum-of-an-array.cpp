class Solution {
public:
    int Sum(int n){
        int s =0;
        while(n>0){
            int d = n%10;
            s = s+d;
            n=n/10;
        }
        return s;
    }
    int differenceOfSum(vector<int>& nums) {
        int sumtotal = 0;
        int sum =0;
        for(auto it : nums){
            sumtotal = sumtotal+it;
            sum = sum+Sum(it);
        }
        
        return abs(sumtotal-sum);
        
        
        
    }
};