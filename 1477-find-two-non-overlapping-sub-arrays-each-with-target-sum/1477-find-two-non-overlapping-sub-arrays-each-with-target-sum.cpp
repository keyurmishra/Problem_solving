class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; 
        int prefix_sum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            prefix_sum += arr[i];
            if (i > 0) {
                dp[i]=dp[i-1];
            }
            if (prefix_map.count(prefix_sum - target)) {
                int start_idx=prefix_map[prefix_sum-target];
                int current_len= i-start_idx;
                if (start_idx>=0 && dp[start_idx]!=INT_MAX) {
                    ans=min(ans,current_len+dp[start_idx]);
                }
                dp[i]=min(dp[i],current_len);
            }
            prefix_map[prefix_sum]=i;
        }
        return (ans==INT_MAX)?-1:ans;
        
    }
};