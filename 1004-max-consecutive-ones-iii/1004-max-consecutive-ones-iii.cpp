class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int left=0;
        int count=0;
        for(int right =0;right<n;right++){
            if(nums[right]==0) count++;
            while(count>k){
                if(nums[left]==0){
                    count--;
                }
                left++;// but left move krna hy to till jab tak count<k nhi ho jata hy 
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};