class Solution {
public:
    int f(string &s, int start, int end, int k){
        unordered_map<char,int>m;
        if(end<k)
            return 0;
        for(int i = start; i<end;i++){
            m[s[i]]++;
        }
        for(int mid = start; mid<end; mid++ ){
            if(m[s[mid]]>=k){
               continue;
            }
             int midN= mid+1;
            while(midN<end && m[s[midN]]< k) midN++;
            return max(f(s,start,mid,k), f(s,midN,end,k));
        }
        return end-start;
    }
    int longestSubstring(string s, int k) {
        return f(s,0,s.size(),k);
    }
};