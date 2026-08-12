class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        unordered_set<int>mpp(nums.begin(),nums.end());
        int x=1;
        while(mpp.find(x)!=mpp.end()){
            x++;
        }
        return x;
        
        
    }
};