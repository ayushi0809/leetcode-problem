class Solution {
public:
    int totalFruit(vector<int>& s) {
        unordered_map<int,int>m;
    int start =0;
    int count =0;
    int mi = -1;
    for(int i =0;i<s.size();i++){
        m[s[i]]++;
        count++;
        if(m.size()<=2){
            mi = max(mi,count);
            
            
        }
        //cout<<mi<<endl;
        //cout<<m.size()<<endl;
        if(m.size()>2){
            m[s[start]]--;
            count--;
            if(m[s[start]] == 0){
                //cout<<s[start]<<endl;
                m.erase(s[start]);
                
                //cout<<m.size()<<endl;
            }
            start++;
        }
    }
    return mi;
        
    }
};