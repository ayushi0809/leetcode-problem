class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        double sum =0;
        for(auto it : salary){
            mini = min(it, mini);
            maxi = max(it, maxi);
            sum = sum+it;
        }
        
        sum = sum - (mini+maxi);
        int n = salary.size()-2;
        
        double ans = sum/n;
        
        return ans;
        
    }
};