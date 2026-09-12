class Solution {
    struct Interval {
        int l, r, weight, id;
    };

    // Compares two index vectors lexicographically
    bool isLexicographicallySmaller(const vector<int>& a, const vector<int>& b) {
        int sz = min(a.size(), b.size());
        for (int i = 0; i < sz; ++i) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return a.size() < b.size();
    }
public:
    
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort by right endpoint to facilitate binary search
        sort(A.begin(), A.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });

        // Extract right endpoints for fast binary search
        vector<int> rights(n);
        for (int i = 0; i < n; ++i) rights[i] = A[i].r;

        // dp[i][k] = {max_weight, vector_of_indices} for prefix i using at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5, {0, {}}));

        for (int i = 1; i <= n; ++i) {
            int l = A[i - 1].l;
            int weight = A[i - 1].weight;
            int id = A[i - 1].id;

            // Find last non-overlapping interval using binary search
            int prevIdx = lower_bound(rights.begin(), rights.end(), l) - rights.begin();

            for (int k = 1; k <= 4; ++k) {
                // Option 1: Skip current interval
                dp[i][k] = dp[i - 1][k];

                // Option 2: Take current interval
                long long takeWeight = dp[prevIdx][k - 1].first + weight;
                vector<int> takeIndices = dp[prevIdx][k - 1].second;
                takeIndices.push_back(id);
                sort(takeIndices.begin(), takeIndices.end()); // Keep indices sorted for comparison

                if (takeWeight > dp[i][k].first) {
                    dp[i][k] = {takeWeight, takeIndices};
                } else if (takeWeight == dp[i][k].first && takeWeight > 0) {
                    if (dp[i][k].second.empty() || isLexicographicallySmaller(takeIndices, dp[i][k].second)) {
                        dp[i][k] = {takeWeight, takeIndices};
                    }
                }
            }
        }

        // Find best choice across k = 1 to 4
        long long maxScore = -1;
        vector<int> bestIndices;

        for (int k = 1; k <= 4; ++k) {
            if (dp[n][k].first > maxScore) {
                maxScore = dp[n][k].first;
                bestIndices = dp[n][k].second;
            } else if (dp[n][k].first == maxScore) {
                if (isLexicographicallySmaller(dp[n][k].second, bestIndices)) {
                    bestIndices = dp[n][k].second;
                }
            }
        }

        return bestIndices;
    
        
    }
};