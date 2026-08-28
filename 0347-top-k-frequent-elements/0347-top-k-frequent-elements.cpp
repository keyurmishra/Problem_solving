class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         int n=nums.size();
         unordered_map<int,int>mp;
         for(int x:nums){
            mp[x]++;
         }
         // here we will build the prioruty queue 
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         //{freq,number}
         //now pushinto minheap 
         for(auto &it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
         }
         vector<int>ans;
         while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
         }
         return ans;
    }
};