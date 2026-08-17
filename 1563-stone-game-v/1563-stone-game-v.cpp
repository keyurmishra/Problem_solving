class Solution {
public:
    int solve(int i, int j, const std::vector<int>& pref, std::vector<std::vector<int>>& memo) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;
        for (int k = i; k < j; k++) {
            int leftSum = pref[k + 1] - pref[i];
            int rightSum = pref[j + 1] - pref[k + 1];

            if (leftSum < rightSum) {
                maxScore = std::max(maxScore, leftSum + solve(i, k, pref, memo));
            } else if (leftSum > rightSum) {
                maxScore = std::max(maxScore, rightSum + solve(k + 1, j, pref, memo));
            } else { 
                int takeLeft = leftSum + solve(i, k, pref, memo);
                int takeRight = rightSum + solve(k + 1, j, pref, memo);
                maxScore = std::max(maxScore, std::max(takeLeft, takeRight));
            }
        }
        return memo[i][j] = maxScore;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));
        return solve(0, n - 1, pref, memo);
        
    }
};