class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize !=0)
            return false;
        unordered_map<int,int>m;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto a : hand){
           // pq.push(a);
            m[a]++;
        }
        
        //sort(hand.begin(), hand.end());
        int j =0;
        for(auto it = m.begin(); it != m.end(); it++){
            pq.push(it->first);
        }
        while(!pq.empty()){
           // int i =j;
            int start =0;
            int h = pq.top();
            while(start<groupSize){
                cout<<h<<endl;
                m[h]--;
                if(m[h]==0){
                    pq.pop();
                }
                if(start+1 != groupSize && m.find(h+1) == m.end()){
                    //cout<<<<endl;
                    return false;
                }
                else{
                    h= h+1;
                }
                start++;
                
            }
            //j=j+k;
        }
        return true;
        
    }
};