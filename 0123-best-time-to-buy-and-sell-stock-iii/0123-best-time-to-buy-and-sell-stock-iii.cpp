class Solution {
public:
    int solve(vector<int>&prices,int n , int i,int buy,int cap,vector<vector<vector<int>>>&dp){
        if((i==n) || (cap==0)) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy==1){
            return dp[i][buy][cap]= max(-prices[i]+solve(prices,n,i+1,0,cap,dp),0+solve(prices,n,i+1,1,cap,dp));
        }
        return dp[i][buy][cap]= max(prices[i]+solve(prices,n,i+1,1,cap-1,dp),0+solve(prices,n,i+1,0,cap,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,n,0,1,2,dp);
        
    }
};