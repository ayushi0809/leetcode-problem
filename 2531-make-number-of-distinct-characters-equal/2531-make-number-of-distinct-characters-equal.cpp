class Solution {
public:
    bool isItPossible(string word1, string word2) {
     unordered_map<char,int>m1,m2;
        
        for(auto it : word1){
           // cout<<it<<endl;
            m1[it]++;
        }
        for(auto it : word2){
            m2[it]++;
        }
        cout<<m1.size()<<" "<<m2.size()<<endl;
        for(char i ='a'; i<='z'; i++){
            for(int j ='a'; j<='z'; j++){
                char ch1 = i;
                char ch2 = j;
               
                if(m1.find(ch1) != m1.end() && m2.find(ch2) != m2.end()){
                    // cout<<ch1<<" ->"<<m1[ch1]<<" "<<ch2<<"->"<<m2[ch2]<<endl;
                    m1[ch1]--;
                    m2[ch2]--;
                    //cout<<m1[ch1]<<" "<<m2[ch2]<<endl;
                    if(m1[ch1]==0){
                        m1.erase(ch1);
                    }
                    if(m2[ch2]==0){
                        m2.erase(ch2);
                    }
                    
                    m1[ch2]++;
                    m2[ch1]++;
                   // cout<<m1[ch2]<<" "<<m2[ch1]<<endl;
                   // cout<<m1.size()<<" "<<m2.size()<<endl;
                    if(m1.size() == m2.size())
                        return true;
                    
                    m2[ch1]--;
                    m1[ch2]--;
                    if(m2[ch1]==0)
                        m2.erase(ch1);
                    if(m1[ch2]==0)
                        m1.erase(ch2);
                    m1[ch1]++;
                    m2[ch2]++;
                }
            }
        }
        
        return false;
        
    }
};