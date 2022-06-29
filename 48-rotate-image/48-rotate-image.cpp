class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        int k=0;
        int j = matrix[0].size()-1;
        while(k<=j){
            for(int i=0;i<n;i++){
                swap(matrix[i][k] , matrix[i][j]);
            }
            k++;
            j--;
        }
        
    }
};