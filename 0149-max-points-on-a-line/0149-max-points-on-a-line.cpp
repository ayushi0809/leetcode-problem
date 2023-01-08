class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
       
       // unordered_map<int,int>mt;
       // unordered_set<int>st;
        int n = points.size();
        if(n==1)
            return 1;
        int maxi = INT_MIN;
        sort(points.begin(),points.end());
        for(int i =0; i<n; i++){
             unordered_map<double,int>m;
            for(int j = i+1; j<n; j++){
                double slope;
                double y1 = points[i][1];
                double x1 = points[i][0];
                double y2 = points[j][1];
                double x2 = points[j][0];
                if(x2 == x1){
                    m[INT_MAX]++;
                }
                else{
                slope = (y2-y1)/(x2-x1);
                m[slope]++;
                }
            }
        for(auto &it : m){
           maxi = max(it.second,maxi); 
        }
        }
       
        
        return maxi+1;
        
    }
};