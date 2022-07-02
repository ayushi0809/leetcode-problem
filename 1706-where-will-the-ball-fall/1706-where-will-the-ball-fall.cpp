class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>v(m);
        int current;
        int next;
        for(int j =0;j<m;j++){
            current =j;
            for(int i=0;i<n;i++){
                next = current+grid[i][current];
                if(next<0 || next>=m || grid[i][next] != grid[i][current]){
                    current =-1;
                    break;
                }
                current = next;
                
            }
            v[j] = current;
            
        }
        return v;
    }
};