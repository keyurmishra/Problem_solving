class Solution {
public:
    int solve(vector<vector<char>>& grid,int i,int j,int balance,vector<vector<vector<int>>>&dp,int m,int n){
        // if (grid[i][j] == '(') balance++;
        // else balance--;
        if(balance<0) return false;
        
        int rem=(m-1-i)+(n-j-1);
        if(balance>rem) return false;
        if(i==m-1 && j==n-1) return balance ==0;
        
        if(dp[i][j][balance] !=-1){
            return dp[i][j][balance];
        }
        bool result=false;
        // move down and the move right 
        if(i+1 <m){
            int newbal=balance;
            if(grid[i+1][j] == '('){
                newbal++;

            }
            else{
                newbal--;
            }
            result=solve(grid,i+1,j,newbal,dp,m,n);
        }
        if(!result && j+1<n){
            int newbal=balance;
            if(grid[i][j+1] =='('){
                newbal++;
            }
            else{
                newbal--;
            }
            result=solve(grid,i,j+1,newbal,dp,m,n);
        }
        return dp[i][j][balance]=result;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //now check is it is even or the odd for the parenthesis 
        if((m+n-1)%2==1) return false;
        int maxbalance=m+n;
        if(grid[0][0]==')') return false;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxbalance+1,-1)));
        return solve(grid,0,0,1,dp,m,n);
        
    }
};