class Solution {
public:
    vector<string>ans;
    void f(int ind,int n, int partition, string s,string s1){
        if(partition>4){
            return ;
        }
        if(ind==n && partition == 4){
            s1.pop_back();
            ans.push_back(s1);
            return;
        }
        for(int i =ind; i<ind+3 && i<n; i++){
            string s2 = s.substr(ind, i-ind+1);
            if((s2.size()>1 && s2[0] == '0') || stoi(s2)>255){
                return ;
            }
            cout<<s1<<endl;
            f(i+1, n, partition+1, s, s1+s2+'.');
        }
    }
    vector<string> restoreIpAddresses(string s) {
       int n = s.size();
        if(n>16 || n<4){
            return {};
        }
        f(0,n,0,s,"");
        return ans;
    }
};