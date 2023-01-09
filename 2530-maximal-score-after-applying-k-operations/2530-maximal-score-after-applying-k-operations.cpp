class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i =0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        long long ans =0;
        while(k>0){
            int it = pq.top();
            pq.pop();
            ans = ans+it;
           if(it%3==0){
            pq.push(it/3);
           }
            else{
                pq.push((it/3)+1);
            }
            k--;
        }
        
        return ans;
        
    }
};