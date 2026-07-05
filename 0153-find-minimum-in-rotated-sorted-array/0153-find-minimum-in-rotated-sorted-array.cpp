class Solution {
public:
    int findMin(vector<int>& nums) {
        // int n=nums.size();
        // int st=0,end=n-1;
        // if(n==0){
        //      return -1;
        // } 
        // while(st<end){
        //     int mid=st+(end-st)/2;
            
        //     if(nums[st]<=nums[end]){
        //       return nums[st];
        //     }
            
        //     if(nums[mid]>nums[end]){
        //         st=mid+1;
        //     }
        //     else{
        //         end=mid;
        //     }
        // }
        // return nums[end];
        sort(nums.begin(),nums.end());
        return nums[0];
        

        
    }
};