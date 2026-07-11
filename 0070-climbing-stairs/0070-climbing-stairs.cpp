class Solution {
public:
    int fibo(int i,vector<int>&dp){
        if(i==0)return 1;
        if(i<0)return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]= fibo(i-1,dp)+fibo(i-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int p=fibo(n,dp);
        return p;
        
        
    }
};