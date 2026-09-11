class Solution {
public:
    int solve(vector<int>&prices,int n,int i , int buy,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            return dp[i][buy]=max(-prices[i]+solve(prices,n,i+1,0,dp) , 0+solve(prices,n,i+1,1,dp));
        }
        return dp[i][buy]=max(prices[i]+solve(prices,n,i+2,1,dp) , 0+solve(prices,n,i+1,0,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,n,0,1,dp);
        
    }
};