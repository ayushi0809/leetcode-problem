class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int left =0;
        int right =n-1;
        int top = 0;
        int bottom =n-1;
        int count =1;
    
        
        while(left<=right || top<=bottom){
            for(int i = left; i<=right;i++){
                matrix[top][i] =count;
                count++;
                
            }
            top=top+1;
            for(int i = top; i<=bottom; i++){
                matrix[i][right] = count;
                count++;
            }
            right = right-1;
            if(left<right && top <bottom){
            for(int i = right; i>=left; i--){
                matrix[bottom][i] = count;
                count++;
            }
            bottom = bottom-1;
            
        
        for(int i = bottom; i>=top; i--){
            matrix[i][left] = count;
            count++;
        }
        left =left+1;
        }
        }
        return matrix;
    }
};