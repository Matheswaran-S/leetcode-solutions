class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(accumulate(gas.begin(), gas.end(),0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        int ind = 0, cst = 0;
        for(int i=0; i<n; i++){
            cst += gas[i] - cost[i];
            if(cst < 0){
                cst = 0;
                ind = i+1;
            }
        } 
        return ind;
    }
};