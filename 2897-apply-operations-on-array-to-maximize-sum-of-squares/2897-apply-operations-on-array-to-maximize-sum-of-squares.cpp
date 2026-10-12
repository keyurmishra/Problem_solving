class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(30, 0);
        int n = nums.size();
        
        // Step 1: Count total set bits at each position
        for (int x : nums) {
            for (int b = 0; b < 30; b++) {
                if ((x >> b) & 1) {
                    bit_count[b]++;
                }
            }
        }
        
        long long total_sum = 0;
        long long MOD = 1e9 + 7;
        
        // Step 2: Greedily build the top k numbers
        vector<long long> top_nums(k, 0);
        for (int b = 29; b >= 0; b--) {
            for (int i = 0; i < k; i++) {
                if (bit_count[b] > 0) {
                    top_nums[i] |= (1LL << b);
                    bit_count[b]--;
                }
            }
        }
        
        // Step 3: Compute the sum of squares modulo 10^9 + 7
        for (int i = 0; i < k; i++) {
            long long val = top_nums[i] % MOD;
            total_sum = (total_sum + (val * val) % MOD) % MOD;
        }
        
        return total_sum;
        
    }
};