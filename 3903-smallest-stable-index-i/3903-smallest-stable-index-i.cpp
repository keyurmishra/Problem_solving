class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // here we have to print the index value which is smaller and equal to the k
        int n=nums.size();
        // actually this is the concept of the prefix and the suffix methode 
        if(n==0) return -1;
        vector<int>suffixmin(n);
        suffixmin[n-1]=nums[n-1];//provding the firdt ele 
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