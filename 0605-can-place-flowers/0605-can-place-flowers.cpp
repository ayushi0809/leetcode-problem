class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int count =0;
        int s = flowerbed.size();
        if(s==1 && n==1 && flowerbed[0]==0)
            return true;
        for(int i =0; i<s; i++){
            if(flowerbed[i]==0){
                if(i==0){
                    cout<<i<<endl;
                    if((i+1)<s && flowerbed[i+1]==0){
                        
                        count++;
                        flowerbed[i] =1;
                    }
                }
                else if(i==s-1){
                    if(flowerbed[i-1]==0){
                        count++;
                        flowerbed[i]= 1;
                    }
                }
                else{
                    if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                        count++;
                        flowerbed[i] =1;
                    }
                }
            }
        }
        return count>=n;
    }
};