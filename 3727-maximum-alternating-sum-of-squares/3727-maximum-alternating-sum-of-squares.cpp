class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squared(n);
        
        // Step 1: Compute squares of all elements
        for (int i = 0; i < n; ++i) {
            squared[i] = 1LL * nums[i] * nums[i];
        }
        
        // Step 2: Sort the squared values in ascending order
        sort(squared.begin(), squared.end());
        
        long long maxScore = 0;
        int mid = n / 2;
        
        // Step 3: Subtract the smaller half and add the larger half
        for (int i = 0; i < n; ++i) {
            if (i < mid) {
                maxScore -= squared[i];
            } else {
                maxScore += squared[i];
            }
        }
        
        return maxScore;
        
    }
};