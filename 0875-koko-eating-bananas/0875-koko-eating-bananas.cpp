class Solution {
public:
    bool check(int k, vector<int> piles, int h){
        int hr = 0;
        for(auto it : piles){
            int t = it/k;
            hr = hr+t;
            if(it%k !=0){
                hr = hr+1;
            }
        }
        if(hr<=h){
            return true;
        }
        else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        int mid;
        
        
        for(auto it : piles){
            right = max(right,it);
        }
        
        while(left<right){
             mid = left+(right-left)/2;
            
            
            if(check(mid,piles,h)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        
        return left;
        
    }
};