class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int c = 1;
        //cout<<matrix[0][0]<<endl;
        for(int i =0; i<matrix.size(); i++){
            for(int j =0; j<matrix[0].size(); j++){
                if(matrix[i][j] ==0){
                    if(i!=0){
                    matrix[0][j] =0;
                    matrix[i][0] =0;
                    }
                    else{
                        matrix[0][j] =0;
                        c=0;
                    }
                }
            }
        }
       
        for(int i =1; i<matrix.size(); i++){
            if(matrix[i][0] ==0){
                for(int j =0; j<matrix[0].size(); j++){
                    matrix[i][j] =0;
                }
            }
        }
       
        for(int i =0; i<matrix[0].size(); i++){
           // cout<<matrix[0][i]<<endl;
            if(matrix[0][i] ==0){
                for(int j =1;j<matrix.size(); j++){
                   // cout<<matrix[j][i]<<endl;
                    matrix[j][i]=0;
                }
            }
        }
        
 if(c==0){
            for(int i =0; i<matrix[0].size(); i++){
                cout<<matrix[0][i]<<endl;
                matrix[0][i] =0;
            }
        }
        
    }
};