class Solution {
public:
    string reverseWords(string s) {
        
        stringstream str(s);
        string rev;
        string ans ="";
        while(getline(str,rev, ' ')){
            if(rev != " "){
                reverse(rev.begin(),rev.end());
                ans=ans+rev+" ";
            }
        }
        ans.pop_back();
        return ans;
        
    }
};