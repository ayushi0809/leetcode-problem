class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        
        vector<bool>v(n,true);
        
        for(int i =2; i*i<n; i++){
            if(v[i] == true){
                for(int j = i*i ; j<n; j = j+i){
                    v[j] = false;
                }
            }
        }
        int count =0;
        for(int i = 2; i<n; i++){
            if(v[i]){
                count++;
            }
        }
       return count; 
    }
};