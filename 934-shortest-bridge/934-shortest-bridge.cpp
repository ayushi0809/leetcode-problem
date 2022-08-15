class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool flag = false;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<int>delta = {0,1,0,-1,0};
        queue<pair<pair<int,int>,int>>q;
        for(int i =0; i<n;i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1 && flag == false){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                    flag = true;
                }
            }
        }
        cout<<q.size()<<endl;
       queue<pair<pair<int,int>,int>>dq;
      while(!q.empty()){
          auto it = q.front();
          q.pop();
          int row = it.first.first;
          int col = it.first.second;
          int count = it.second;
          dq.push({{row,col},count});
          for(int i =0; i<4; i++){
              int r = row+delta[i];
              int c = col+delta[i+1];
              if(r>=0 &&r<n && c>=0 && c<n && grid[r][c] == 1 && vis[r][c] == false){
                  vis[r][c] = true;
                  q.push({{r,c},0});
              }
          }
      }
        cout<<dq.size()<<endl;
        while(!dq.empty()){
          auto it = dq.front();
          dq.pop();
          int row = it.first.first;
          int col = it.first.second;
          int count = it.second; 
           for(int i =0; i<4; i++){
              int r = row+delta[i];
              int c = col+delta[i+1];
              if(r>=0 &&r<n && c>=0 && c<n && vis[r][c] == false){
                  if(grid[r][c] == 1){
                      return count;
                  }
                  vis[r][c] = true;
                  dq.push({{r,c},count+1});
              }
          } 
        }
        return 0;
    }
};