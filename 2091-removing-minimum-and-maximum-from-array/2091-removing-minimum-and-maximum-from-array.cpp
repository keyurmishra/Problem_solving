class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[maxi]) maxi=i;
        }
        int mini=0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[mini]) mini=i;
        }
        int l=min(maxi,mini);
        int r=max(mini,maxi);
        // deletion can be take from the front back and both 
        int front=r+1;
        int back=n-l;
        int both=(l+1)+(n-r);
        return min({front,back,both});

        
    }
};