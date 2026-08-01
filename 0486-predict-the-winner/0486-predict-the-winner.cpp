class Solution {
public:
    int solve(int i,int j , vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(i==j)return nums[i];
        
        if(dp[i][j]!=-1) return dp[i][j];

        int take_i=nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int take_j=nums[j]+min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
        return dp[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int total_size=accumulate(nums.begin(),nums.end(),0);
        int p1=solve(0,n-1,nums,dp);
        int p2=total_size - p1;
        return p1>=p2;
        
    }
};