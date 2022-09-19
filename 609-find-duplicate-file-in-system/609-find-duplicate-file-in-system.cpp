class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>m;
        vector<vector<string>>ans;
        
        int n = paths.size();
        
        for(int i =0; i<n; i++){
            stringstream s(paths[i]);
            string str;
            bool flag = true;
             string path= "";
            while(getline(s,str,' ')){
                if(flag){
                    path=str;
                    //cout<<path<<endl;
                    flag = false;
                }
                else{
                    int pos = str.find('(');
                    cout<<path<<endl;
                    string s = path+'/'+str.substr(0,pos);
                    string content = str.substr(pos+1);
                    content.pop_back();
                   // cout<<s<<" "<<content<<endl;
                    m[content].push_back(s);
                }
            }
        }
        
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second.size()>1){
                ans.push_back(it->second);
            }
        }
        
        return ans;
        
    }
};