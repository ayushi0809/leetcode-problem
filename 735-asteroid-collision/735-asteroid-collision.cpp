class Solution {
public:
    vector<int> asteroidCollision(vector<int>& s) {
   // int n = asteroids.size();
        stack<int>st;
        int explode=0;
        for(auto x : s){
            if(x<0){
                if(st.empty()){
                    st.push(x);
                }
                else if(!st.empty() && st.top()<0){
                    st.push(x);
                }
                
                else{
                    while(!st.empty() && st.top()>0 && st.top()<= abs(x) ){
                        if(st.top()==abs(x)){
                          st.pop();
                            explode =1;
                            break;
                }       
                        st.pop();
                        }
                    cout<<explode<<endl;
                    if(!explode && (st.empty() || st.top() < 0)){
                        cout<<"hi"<<endl;
                        st.push(x);
                    }
                }
                explode =0;
            }
            
            else{
                st.push(x);
            }
        }
        int n = st.size();
        vector<int>v(n);
        while(!st.empty()){
            v[n-1] = st.top();
            st.pop();
            n--;
        }
        return v;
        
        
       
    }
};