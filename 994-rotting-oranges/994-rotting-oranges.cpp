class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        int fresh=0;
        int notfresh =0;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j] == 2){
                    notfresh++;
                }
            }
        }
        vector<int>delta = {0,1,0,-1,0};
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }}
        int count =0;
        if(fresh==0)
            return 0;
        while(!q.empty()){
            int s = q.size();
            while(s){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
           
            for(int i =0; i<4; i++){
                int r = row+delta[i];
                int c = col+delta[i+1];
                if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 1){
                    //count++;
                    grid[r][c] = 2;
                    q.push({r,c});
                    fresh--;
                }
            }
                s--;
               
            }
             count++;
            
        }
        cout<<fresh<<endl;
        if(fresh!=0)
            return -1;
        return count-1;
    }
};