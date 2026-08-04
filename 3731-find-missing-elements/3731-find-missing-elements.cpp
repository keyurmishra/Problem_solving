class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        //here we will solve in two ways 
        int n=nums.size();
        unordered_set<int>m(nums.begin(),nums.end());
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int x:nums){
            mini=min(x,mini);
            maxi=max(x,maxi);
        }
        vector<int>ans;
        for(int i=mini+1;i<maxi;i++){
            if(m.find(i)==m.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};