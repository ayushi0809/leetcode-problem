class Solution {
public:
    int bestClosingTime(string customers) {
         int n = customers.size();
        vector<int>left(n+1,0);
         vector<int>right(n+1,0);
      
        
        for(int i =0; i<n; i++){
            if(customers[i] == 'Y'){
                left[i+1] = left[i]+1;
                right[i+1] = right[i];
            }
            else{
                left[i+1] = left[i];
                right[i+1] = right[i]+1;
            }
            
        }
        
        int min_index= INT_MAX;
        int min_penality=INT_MAX;
       
        
        for(int i = 0; i<n+1; i++){
            int p = left[n]-left[i]+right[i];
            cout<<p<<endl;
            if(p<min_penality){
                min_penality = p;
                min_index = i;
            }
            if(p==min_penality){
                min_index = min(i,min_index);
            }
            
        }
        
        return min_index;
        
    }
};