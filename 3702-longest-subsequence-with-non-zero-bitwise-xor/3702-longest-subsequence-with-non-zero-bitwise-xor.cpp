class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalxor=0;
        bool hasnonzero=false;
        for(int num:nums){
            totalxor^=num;
            if(num!=0) hasnonzero=true;
        }
        if(totalxor!=0) return nums.size();
        if(hasnonzero) return nums.size()-1;
        return 0;
        
    }
};