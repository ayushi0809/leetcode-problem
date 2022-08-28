class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>mp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                int r = i;
                int c = j;
               
                    mp[r-c].push_back(mat[r][c]);
            }
        }
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                int r = i; 
                int c = j;
                auto it  = mp.find(r-c);
                if(it != mp.end()){
                sort(it->second.begin(), it->second.end());
                int index =0;
                while(r<n && c<m){
                    mat[r][c] = it->second[index++];
                    r++;
                    c++;
                }
                mp.erase(r-c);
                }
                
            }
        }
        
        return mat;
    }
};