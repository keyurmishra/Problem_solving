class Solution {
public:
    int numberOfSets(int n, int k) {
        int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        vector<long long> pref(k + 1, 0);
        dp[1][0] = 1;
        pref[0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + pref[j - 1]) % MOD;
                }
                
            }
            for(int j=0;j<=k;j++){
                pref[j] = (pref[j] + dp[i][j]) % MOD;
            }
        }
        return dp[n][k];
        
    }
};