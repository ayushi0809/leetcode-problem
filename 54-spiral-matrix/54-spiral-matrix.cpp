class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>v(n*m);
        int cstart =0;
        int cend=m-1;
        int index =0;
        int rstart=0;
        int rend=n-1;
        //cout<<cend<<endl;
       while(rstart<=rend && cstart<=cend){
           if(rstart<=rend){
           for(int i = cstart; i<=cend; i++){
               v[index] = matrix[rstart][i];
               //cout<<v[index]<<endl;
                              //cout<<i<<endl;

               index++;
           }
           rstart++;
           }
           if(cstart<=cend){
           for(int i = rstart; i<=rend; i++){
               v[index] = matrix[i][cend];
                              //cout<<v[index]<<endl;

               index++;
           }
           cend--;
           }
           if(rstart<=rend){
           for(int i = cend; i>=cstart;i--){
               v[index] = matrix[rend][i];
                              //cout<<v[index]<<endl;

               index++;
           }
           rend--;
           }
           if(cstart<=cend){
           for(int i=rend;i>=rstart;i--){
               v[index] = matrix[i][cstart];
                              //cout<<v[index]<<endl;

               index++;
           }
           cstart++;
           }
           cout<<rstart<<" "<<rend<<" "<<cstart<<" "<<cend<<endl;
       }
        
       return v; 
    }
};