class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        while(n>1){
            sort(stones.begin(), stones.end());
            if(stones[n-1] == stones[n-2]){
                stones[n-1]=INT_MAX;
                stones[n-2]=INT_MAX;
                n =n-2;
            }
            else{
                stones[n-2] = stones[n-1]-stones[n-2];
                stones[n-1] = INT_MAX;
                n =n-1;
            }
        }
        if(n==0){
            return 0;
        }
        else{
            return stones[0];
        }
        
    }
};