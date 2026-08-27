class Solution {
public:
    int solve(int i,vector<int>&cost,vector<int>&dp){
        // if(i==0 || i==1 )return cost[i];
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int single=solve(i+1,cost,dp);
        int doublee =solve(i+2,cost,dp);
        return dp[i]=cost[i]+min(single,doublee);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
        
    }
};