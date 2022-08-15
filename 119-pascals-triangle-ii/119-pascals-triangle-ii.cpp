class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //vector<vector<int>>v(rowIndex+1);
        if(rowIndex==0){
            return {1};
        }
        if(rowIndex==1){
            return {1,1};
        }
        vector<int>v = {1,1};
        
        for(int i =2; i<=rowIndex; i++){
            vector<int>vec(i+1);
            for(int j =0; j<=i; j++){
                if(j==0 || j==i){
                    vec[j] = 1;
                }
                else{
                    //cout<<v[j]<<" "<<v[j+1]<<endl;
                    vec[j] = v[j-1]+v[j];
                }
            }
            v = vec;
        }
        return v;
    }
};