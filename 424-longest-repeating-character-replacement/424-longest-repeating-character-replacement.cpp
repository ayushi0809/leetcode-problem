class Solution {
public:
    int freq(unordered_map<char,int> &m){
        int maxi = INT_MIN;
        
        for(auto it : m){
            maxi = max(maxi, it.second);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int start =0;
        int i =0;
        int res = 0;
        unordered_map<char,int>m;
        
        for(i =0; i<n; i++){
            m[s[i]]++;
            
            if((i-start+1) - freq(m) > k){
                m[s[start]]--;
                start=start+1;
            }
            
           res = max(res,i-start+1); 
        }
        return res;
    }
};