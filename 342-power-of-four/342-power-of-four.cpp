class Solution {
public:
    bool isPowerOfFour(int n) {
         int x = abs(n);
        int count =0;
        if(n<=0){
            return false;
        }
        while(x>1){
            if(x%4!=0){
                return false;
            }
            x=x/4;
            count++;
        }
       
        return true;
    }
};