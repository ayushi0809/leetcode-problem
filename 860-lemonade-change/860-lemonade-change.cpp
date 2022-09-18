class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int sum =0;
        int n = bills.size();
        unordered_map<int,int>m;
        m[5]=0;
        m[10] = 0;
        m[20] = 0;
        for(int i =0; i<n; i++){
            if(bills[i]==5){
                m[5]++;
            }
            else if(bills[i]==10){
                if(m[5]==0){
                    cout<<"10"<<endl;
                    return false;
                }
                else{
                    m[5]--;
                    m[10]++;
                }
            }
            else{
                
                if(m[5]>0 && m[10]>0){
                     m[5]--;
                    m[10]--;
                    m[20]++;
                }
                else if(m[5]>=3){
                    m[5] = m[5]-3;
                    m[20]++;
                }
                else{
                    cout<<i<<endl;
                   return false;
                }
            }
        }
        return true;
    }
};