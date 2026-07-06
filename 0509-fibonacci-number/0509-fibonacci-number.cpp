class Solution {
public:
    // vector<int>dp=vector<int>(31,-1);// size must be max constraint 
    // int fib(int n) {
    //     if(n==0 || n==1){
    //         return n;
    //     }
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=fib(n-1)+fib(n-2);
        
    // }
    int fib(int n){
        vector<int>dp(n+1);
        dp[0]=0;
        if(n>=1)dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};