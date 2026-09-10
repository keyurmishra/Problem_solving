class Solution {
public:
    int solve(int idx,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        long long profit=0;
        if(buy){
            profit=max(-prices[idx]+solve(idx+1,0,prices,n,dp),0+solve(idx+1,1,prices,n,dp));
        }
        else{
            profit=max(prices[idx]+solve(idx+1,1,prices, n , dp) , solve(idx+1,0,prices,n , dp));
        }
        return dp[idx][buy]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,n,dp);
        
        // int profit=0;
        
        // for(int i=1;i<prices.size();i++){
        //     //maxprofit
        //     if(prices[i]>prices[i-1]){
        //         profit+=prices[i]-prices[i-1];
        //     }
           
           
        // }
        // return profit;
        
    }
};