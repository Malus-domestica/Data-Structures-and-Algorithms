class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum_gas=0;
        int sum_cost=0;
        for(int i=0;i<n;i++)sum_gas+=gas[i];
        for(int i=0;i<n;i++)sum_cost+=cost[i];
        if(sum_gas < sum_cost)return -1;
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i] = gas[i] - cost[i];
        }
        int sum = 0;
        int ind=-1;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum>=0 and ind==-1)ind=i;
            if(sum<0){
                sum=0;
                ind =-1;
            }
        }
        return ind;
    }
};