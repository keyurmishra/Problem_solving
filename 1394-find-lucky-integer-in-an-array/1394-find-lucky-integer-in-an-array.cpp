class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int x:arr){
            mp[x]++;
        }
        int ans=INT_MIN;
        for(auto &it:mp){
            if(it.second==it.first){
                ans=max(ans,it.first);
            }
        }
        return (ans==INT_MIN)?-1:ans;
        
    }
};