class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n));
        int maxl=0;
        int idx=0;
        //one lenght
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            maxl=1;
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
               int j=i+l-1;
               if(s[i]==s[j] && l==2){
                dp[i][j]=true;
                maxl=2;
                idx=i;
               } 
               else if(s[i]==s[j] && dp[i+1][j-1] == true){
                dp[i][j]=true;
                if(l>maxl){
                    maxl=l;
                    idx=i;
                }
                
               }
                else{
                    dp[i][j]=false;
                }
            }
            
        }
        return s.substr(idx,maxl);

        
    }
};