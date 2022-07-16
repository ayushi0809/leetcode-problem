class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       int n = points.size();
        //vector<int>parent(1001, -1);
        vector<int>key(n,INT_MAX);
        vector<bool>mst(n, false);
        int count =0;
        int sum=0;
        key[0]=0;
        while(count<n){
           int mini = INT_MAX;
            int u;
            for(int v=0; v<n; v++){
                if(mst[v]==false && key[v]< mini){
                    mini = key[v];
                    u=v;
                }
            }
            sum = sum+mini;
            count++;
            mst[u] = true;
            
        for(int i=0; i<n; i++){
            int wt = abs(points[u][0] - points[i][0])+abs(points[u][1]- points[i][1]);
            if(!mst[i] && key[i]>wt){
                key[i] = wt;
            }
        }
        }
        return sum;
    }
};