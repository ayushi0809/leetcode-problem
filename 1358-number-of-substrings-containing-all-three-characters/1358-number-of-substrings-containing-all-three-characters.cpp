class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i =0;
        int j =0;
        int count =0;
        unordered_map<char,int>m;
        
        while(j<n){
           while(j<n and m.size()<3)
          {
             m[s[j]]++;	
             j++;
          }
            while(m.size()==3){
                count = count+n-j+1;
                m[s[i]]--;
                if(m[s[i]] == 0){
                    m.erase(s[i]);
                }
                i++;
            }
            cout<<j<<endl;
        }
       return count; 
    }
};