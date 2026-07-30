class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0;
        int currtank=0;
        int st=0;
        for(int i=0;i<gas.size();i++){
            int remain=gas[i]-cost[i];
            totalgas+=remain;
            currtank+=remain;
           
            if(currtank<0){
                st=i+1;
                currtank=0;
            }
        }
        if(totalgas<0){
                return -1;
        }
        return st;
        
    }
};