class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string st;
        for(int i=0;i<strs[0].length();i++){
            bool flag = true;
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                st+=strs[0][i];
            }else{
                break;
            }
        }
        return st;
    }
};