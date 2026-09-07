class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        std::vector<long long> last(26, 0);
        for (char c : s) {
            long long current_sum = 0;
            for (int count : last) {
                current_sum = (current_sum + count) % MOD;
            }
            last[c - 'a'] = (current_sum + 1) % MOD;
        }
        long long total = 0;
        for (int count : last) {
            total = (total + count) % MOD;
        }
        return total;
        
    }
};