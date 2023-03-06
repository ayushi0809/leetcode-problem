class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        unordered_set<int>st(arr.begin(),arr.end());
        while(i<=1000 && k > 0){
            if(st.find(i) == st.end()){
                k--;
            }
            i++;
        }
        if(k != 0){
            return i+k-1;
        }
        
        return i-1;
        
    }
};