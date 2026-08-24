class Solution {
public:
    // int solve(vector<int>&nums1 , vector<int>&nums2 ,vector<vector<int>>&dp,int i,int j ,int max_length){

     
    // //     //base case 
    // //     if(i<0 || j<0)return 0;
    // //     if(dp[i][j]!=-1) return dp[i][j];
    // //     int length=0;
        
    // //     if(nums1[i] == nums2[j]){
    // //         length=1+solve(nums1,nums2,dp,i-1,j-1,max_length);
    // //     }
    // //     else{
    // //         length=0;
    // //     }
    // //     max_length=max(max_length,length);
    // //     return dp[i][j]=length;
    // // }
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        for(int i=0;i<=n1;i++) dp[i][0]=0;
        for(int j=0;j<=n2;j++) dp[0][j]=0;
        int ans=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;

    //     int max_length=0;
    //     // here it is the similiar to the longest common substring 
    //     //we have to use the dp here 
    
    //     for(int i=0;i<n1;i++){
    //         for(int j=0;j<n2;j++){
    //             solve(nums1,nums2,dp,i,j,max_length);

    //         }
    //     }
    //     return max_length;

        
    }
};