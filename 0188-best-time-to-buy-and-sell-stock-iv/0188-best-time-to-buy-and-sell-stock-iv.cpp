class Solution {
public:
    // int solve(vector<int>&prices, int n ,int i,int trans,int k,vector<vector<int>>&dp){
    //     if(i==n || trans==2*k) return 0;
    //     if(dp[i][trans]!=-1) return dp[i][trans];
    //     // if k=2 then tranc will be double like sb sb =4
    //     if(trans%2==0){
    //         return dp[i][trans]=max(-prices[i]+solve(prices,n,i+1,trans+1,k,dp) , 0+solve(prices,n,i+1,trans,k,dp));
    //     }
        
    //     return dp[i][trans]=max(prices[i]+solve(prices,n,i+1,trans+1,k,dp),0+solve(prices,n,i+1,trans,k,dp));
        
    // }
    int maxProfit(int k, vector<int>& prices) {
        // int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2*k,-1));
        // return solve(prices,n,0,0,k,dp);
        //TABULATION PART 
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int trans=2*k-1;trans>=0;trans--){
                if(trans%2==0){
                    dp[i][trans]=max(-prices[i]+dp[i+1][trans+1] , 0+dp[i+1][trans]);
                }
                else{
                    dp[i][trans]=max(prices[i]+dp[i+1][trans+1] , 0+dp[i+1][trans]);
                }
            }
        }
        return dp[0][0];
        
    }
};