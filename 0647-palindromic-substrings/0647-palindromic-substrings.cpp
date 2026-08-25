class Solution {
public:
    int check(int i,int j,string&s,vector<vector<int>>&dp){
        if(i>j)return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=check(i+1,j-1,s,dp);
        }
        return dp[i][j]=0;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s,dp)){
                    count++;
                }
            }
        }
        return count;
        
    }
};