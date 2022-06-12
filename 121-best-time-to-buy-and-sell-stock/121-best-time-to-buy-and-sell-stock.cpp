class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m =0;
        int price = INT_MAX;
        for(int i =0; i<prices.size(); i++){
            price = min(price, prices[i]);
            m = max(m, prices[i]-price);
           
        }
        return m;
        
    }
};