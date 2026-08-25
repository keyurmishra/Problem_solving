class Solution {
public:
    // int check(int i,int j,string&s,vector<vector<int>>&dp){
    //     if(i>j)return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j]){
    //         return dp[i][j]=check(i+1,j-1,s,dp);
    //     }
    //     return dp[i][j]=0;
    // }
    int countSubstrings(string s) {
        // int n=s.length();
        // int count=0;
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(check(i,j,s,dp)){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int count=0;
        for(int l=1;l<=n;l++){
            for(int i=0;(i+l-1)<n;i++){
                int j=i+l-1;
                if(i==j) dp[i][j]=true;
                else if((i+1)==j) dp[i][j]=(s[i]==s[j]);
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]==true){
                    count++;
                }

            }
        }
        return count;
        
    }
};