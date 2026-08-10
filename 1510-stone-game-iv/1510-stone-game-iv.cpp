class Solution {
public:
    bool solve(int n , vector<int>&dp){// yhe jo ans nikaal rhy is for the Alice only 
       if(n==0) return false;
       if(dp[n]!=-1) return dp[n];
       for(int k=1;k*k<=n;k++){
        if(solve(n-(k*k), dp) ==false){// yhe bob ka scene hy jisme vo false aa gya 
            return dp[n]=true;

        }
       }
       return dp[n]=false;

    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        //particularlly N is changing here 
        return solve(n,dp);

        
    }
};