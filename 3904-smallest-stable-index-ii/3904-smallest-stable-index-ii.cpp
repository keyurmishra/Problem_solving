class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return -1;
        }
        vector<int>suffixmin(n);
        suffixmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixmin[i]=min(nums[i],suffixmin[i+1]);
        }
        int currmax=nums[0];
        for(int i=0;i<n;i++){
            currmax=max(currmax,nums[i]);
            int diff=currmax - suffixmin[i] ;
            if(diff<=k){
                return i;
            }
        }
        return -1;
    }
};