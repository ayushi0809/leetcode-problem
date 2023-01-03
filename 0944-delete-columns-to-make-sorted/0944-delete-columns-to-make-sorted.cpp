class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int count =0;
        int n = strs[0].size();
        for(int i =0; i<n; i++){
            for(int j =0; j<strs.size()-1; j++){
             if(strs[j][i]>strs[j+1][i]){
                 count++;
                 break;
             }   
            }
        }
        
        return count;
        
    }
};