#define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        vector<int>left_small;
        int n = arr.size();
        vector<int>right_small(n,0);
        
        for(int i =0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty())
                left_small.push_back(i+1);
            else
                left_small.push_back(i-st.top());
            st.push(i);
        }
        
        stack<int>st1;
        
        for(int i = n-1; i>=0; i--){
            while(!st1.empty() && arr[st1.top()] > arr[i]) st1.pop();
            if(st1.empty())
                right_small[i] = n-i;
            else
                right_small[i] = st1.top()-i;
            st1.push(i);
        }
        long long sum =0;
        for(int i =0; i<n; i++){
            cout<<left_small[i]<<" "<<right_small[i]<<endl;
            sum = (sum+((long long)arr[i]*(long long)left_small[i]*(long long)right_small[i]))%mod;
        }
        return (int)sum;
    }
};