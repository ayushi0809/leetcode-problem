class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int>degree(n,0);
        vector<vector<int>>v(n, vector<int>(n,0));
        
        for(auto it : roads){
            degree[it[0]]++;
            degree[it[1]]++;
            v[it[0]][it[1]] =  1;
            v[it[1]][it[0]] = 1;
        }
        int maxi = INT_MIN;
        int sum =0;
       for(int i =0; i<n; i++){
           for(int j = i+1; j<n; j++){
                sum = degree[i]+degree[j] - v[i][j];
               cout<<degree[i]<<" "<<degree[j]<<" "<<sum<<endl;
               
               maxi = max(maxi,sum);
           }
       }
        
        return maxi;
        
    }
};