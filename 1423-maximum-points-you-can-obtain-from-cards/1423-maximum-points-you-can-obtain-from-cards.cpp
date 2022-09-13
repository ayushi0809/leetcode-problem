class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxi = INT_MIN;
        //int sum =0;
        int start =0;
        int end =0;
        int i = 0;
        int j = 0;
        
        int total_sum=0;
        
        for(auto a : cardPoints){
            total_sum = total_sum+a;
        }
        //cout<<total_sum<<endl;
        while(j<n){
            if(j-i<n-k){
                total_sum= total_sum-cardPoints[j];
            }
           
            while(j-i==n-k){
                maxi = max(maxi,total_sum);
                total_sum-=cardPoints[j];
                total_sum+=cardPoints[i];
                 cout<<total_sum<<endl;
                i++;
                
            }
            j++;
        }
        maxi = max(maxi,total_sum);
        return maxi;
    }
};