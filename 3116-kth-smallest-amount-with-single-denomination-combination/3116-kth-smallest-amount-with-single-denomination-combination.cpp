class Solution {
private:
    long long lcm(long long a, long long b) {
        return (a / std::gcd(a, b)) * b;
    }
    long long countAmounts(long long M, const std::vector<int>& coins) {
        int n = coins.size();
        long long count = 0;
        for(int mask = 1; mask < (1 << n); mask++) {
            long long currentLcm = 1;
            int setBits = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    setBits++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    if (currentLcm > M) break;
                }
            }
            if(currentLcm <= M) {
                if(setBits % 2 == 1) {
                    count += M / currentLcm;
                }else {
                    count -= M / currentLcm;
                }
            }
        }
        return count;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high=1LL*(*std::min_element(coins.begin(), coins.end())) * k;
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if(countAmounts(mid, coins)>= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            }else {
                low = mid + 1;
            }
        }
        return ans;
        
    }
};