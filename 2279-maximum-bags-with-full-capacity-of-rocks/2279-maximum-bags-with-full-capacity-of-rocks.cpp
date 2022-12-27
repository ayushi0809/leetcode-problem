class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int &additionalRocks) {
        vector<int>v(rocks.size());
        for(int i =0; i<rocks.size(); i++){
            v[i] = capacity[i]-rocks[i];
        }
        sort(v.begin(),v.end());
        for(int i =0; i<v.size(); i++){
            //cout<<v[i]<<endl;
            if(v[i]==0){
                continue;
            }
           else if(additionalRocks==0){
                break;
            }
            else if(v[i]<=additionalRocks){
               // cout<<v[i]<<" "<<additionalRocks<<endl;
                additionalRocks = additionalRocks-v[i];
                v[i] = 0;
            }
            
        }
        int count =0;
        for(auto it : v){
            // cout<<it<<endl;
            if(it==0){
                count++;
            }
        }
        
        return count;
        
    }
};