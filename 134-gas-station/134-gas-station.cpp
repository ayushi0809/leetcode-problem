class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum_gas=0;
        int sum_cost =0;
       vector<int>diff(n);
        for(int i=0; i<n; i++){
            diff[i] = gas[i]-cost[i];
            sum_gas = sum_gas+gas[i];
            sum_cost = sum_cost+cost[i];
        }
        if(sum_gas<sum_cost)
            return -1;
        int total =0;
        int i =0;
        int start =0;
        while(i<n){
            //int start = i;
            total = total+diff[i];
            if(total<0){
                total=0;
                //i=i+1;
                start = i+1;
                //cout<<start<<endl;
            }
            i++;
        }
        if(total>=0)
            return start;
        return -1;
    }
};