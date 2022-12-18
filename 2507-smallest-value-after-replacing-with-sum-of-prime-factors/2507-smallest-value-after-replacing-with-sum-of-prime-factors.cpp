class Solution {
public:
    int sumofprimefactors(int n){
        int sum =0;
        while(n%2==0){
         sum=sum+2;
            n=n/2;
        }
        for(int i =3; i<=sqrt(n); i++){
            while(n%i==0){
                sum=sum+i;
                n=n/i;
            }
        }
        if(n>2){
            sum =sum+n;
        }
        
        return sum;
    }
    int smallestValue(int n) {
        int ans= sumofprimefactors(n);
        while(n!=ans){
            n = ans;
            ans = sumofprimefactors(n);
        }
        
        return n;
        
    }
};