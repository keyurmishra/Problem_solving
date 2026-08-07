class Solution {
public:
    int solve(int d, vector<vector<int>>&dp,vector<int>&jobDifficulty,int n ,int idx){
        if(d==1){
         int maxi=INT_MIN;
         for(int i=idx;i<n;i++){
            maxi=max(maxi,jobDifficulty[i]);
         }
         return maxi;
        }
       
       if(dp[idx][d]!=-1) return dp[idx][d];
       int maxii=INT_MIN;
       int final=INT_MAX;
       for(int i=idx;i<=n-d;i++){
        maxii=max(maxii,jobDifficulty[i]);
        int result=maxii+solve(d-1,dp,jobDifficulty,n,i+1);
        final=min(final,result);
       }
       return dp[idx][d]=final;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return solve(d,dp,jobDifficulty,n,0);

        
    }
};