class Solution {
public:
    int getsum(int n){
        int s =0;
        while(n){
            int d=n%10;
            s=s+d*d;
            n=n/10;
        }
        return s;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getsum(n);
        while(fast != 1 && slow !=fast){
            slow = getsum(slow);
            fast = getsum(getsum(fast));
        }
        return fast == 1;
    }
};