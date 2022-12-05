class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>v(numRows);
        int j = 0;
        int i =0;
        while(i<s.size()){
            while(j<numRows && i<s.size()){
                //cout<<s[i]<<endl;
                v[j].push_back(s[i]);
                i++;
                j++;
            }
            j=j-2;
           // i++;
           // cout<<j<<endl;
            while(j>0 && i<s.size()){
                v[j].push_back(s[i]);
               // cout<<v[1][0]<<" "<<v[1][1]<<endl;
                i++;
                j--;
            }
            j=0;
           // i++;
        }
        string ans="";
        for(int i =0; i<numRows;i++){
            for(int k=0; k<v[i].size(); k++){
                ans=ans+v[i][k];
            }
            //cout<<endl;
        }
        
        return ans;
        
    }
};