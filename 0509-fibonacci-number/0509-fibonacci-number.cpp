class Solution {
public:
    vector<int>dp=vector<int>(31,-1);// size must be max constraint 
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fib(n-1)+fib(n-2);
        
    }
};