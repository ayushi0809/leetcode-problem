class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        for(int i =0; i<=n;i++){
            arr.push_back(bit(i));
        }
        return arr;
    }
    int bit(int i){
        if(i==0){
            return 0;
        }
        if(i==1){
            return 1;
        }
        if(i%2==0){
            return bit(i/2);
        }
        else{
            return 1+bit(i/2);
        }
    }
};