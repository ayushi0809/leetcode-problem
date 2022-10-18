class Solution {
public:
    string mapfunction(vector<pair<char,char>>v, string n){
        //cout<<n<<endl;
        string str = n;
        int s = str.size();
        int start =0;
        int end = 1;
        char ch = str[0];
       // cout<<str[0]<<endl;
        int len;
        while(end<s){
            if(ch != str[end]){
                 len = end-start;
                cout<<ch<<" "<<len<<endl;
                v.push_back({ch , len+'0'});
                start = end;
            }
            ch = str[end];
            end++;
        }
        len = end-start;
        v.push_back({ch, len+'0' });
        string ans = "";
        for(auto it : v){
            cout<<it.second<<" "<<it.first<<endl;
            ans = ans+it.second+it.first;
        }
        cout<<ans<<endl;
        return ans;
        
    }
    string countAndSay(int n) {
       vector<pair<char,char>>v;
        if(n==1)
            return "1";
        string j = mapfunction(v,"1");
        
        while(n>2){
            v.clear();
            string a = mapfunction(v,j);
            j=a;
            n--;
        }
        cout<<j<<endl;
        
        return j;
    }
};