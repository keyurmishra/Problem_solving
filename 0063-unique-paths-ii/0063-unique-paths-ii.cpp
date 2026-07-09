class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int i ,int j,vector<vector<int>>&dp){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(i>=m || j>=n || obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=solve(obstacleGrid,i,j+1,dp)+ solve(obstacleGrid,i+1,j,dp);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(obstacleGrid,0,0,dp);
        
    }
};