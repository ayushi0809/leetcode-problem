class Solution {
public:
    int longestContinuousSubstring(string s) {
       int n = s.size();
        int start =0;
        int end =1;
        char ch = s[0];
        int res = 1;
        while(end<n){
            if(s[end]-ch==1){
                ch = s[end];  
                
            }
            else{
                res = max(res, end-start);
                start = end;
            }
            ch = s[end];
            end++;
        }
        
        res = max(res, end-start);
        return res;
        
    }
};