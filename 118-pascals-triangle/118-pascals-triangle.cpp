class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec(numRows);
        vec[0].push_back({1});
        vector<int>v;
        for(int i =1; i<numRows; i++){
            for(int j =0; j<=i; j++){
                if(j==0 || j==i){
                    //cout<<"ay"<<endl;
                    v.push_back(1);
                }
                else{
                    
                    v.push_back(vec[i-1][j-1]+vec[i-1][j]);
                }
            }
            //cout<<v[0]<<endl;
            //cout<<i<<endl;
            vec[i] = v;
            //cout<<vec[i][0]<<endl;
            v.clear();
        }
        return vec;
    }
};