class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even =0;
        int odd =0;
        int binaryNum[32];
 
   
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
        for(int j = i-1; j>=0; j--){
            if(j%2==0 && binaryNum[j] == 1){
                even++;
            }
            if(j%2 && binaryNum[j]){
                odd++;
            }
        }
        return {even,odd};
        
    }
};