class Solution {
public:
    int solve(int idx,vector<int>&arr,vector<int>&dp){
        if(idx==0)return arr[idx];
        if(idx<0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int pick=arr[idx]+solve(idx-2,arr,dp);
        int notpick=0+solve(idx-1,arr,dp);
        return dp[idx]=max(pick,notpick);
    }
    int adjsum(vector<int>&arr){
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(n-1,arr,dp);
        // int prev=arr[0];//dp[0]base case
        // int prev2=0;// neagtive dipict 
        // for(int i=1;i<n;i++){
        //     int pick=arr[i];
        //     if(i>1) pick+=prev2;
        //     int notpick=0+prev;
        //     int curr=max(pick,notpick);
        //     prev2=prev;
        //     prev=curr;
        // }
        // return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(adjsum(temp1),adjsum(temp2));
        
    }
};