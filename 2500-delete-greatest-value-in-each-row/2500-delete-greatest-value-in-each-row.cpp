class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i =0; i<m; i++){
            sort(grid[i].begin(),grid[i].end());
        }
        int index = n-1;
        int sum =0;
        while(index>=0){
            int mi = INT_MIN;
        for(int i =0; i<m; i++){
            mi = max(mi, grid[i][index]);
            //cout<<m<<endl;
            
        }
            sum=sum+mi;
            index--;
        }
     return sum;   
    }
};