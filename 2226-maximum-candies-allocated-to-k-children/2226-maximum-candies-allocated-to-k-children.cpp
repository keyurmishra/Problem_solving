class Solution {
public:
    bool ispossible(vector<int>&candies,int mid,long long k){
        long long count=0;
        for(int ht:candies){
            count+=ht/mid;
            if(count>=k){
                return true;
            }
            
        }
        
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int st=1;
        int mn=*max_element(candies.begin(),candies.end());
        int end=mn;
        int ans=0;
        long long total=0;
        for(int i=0;i<n;i++){
           total+=candies[i];
        }
        if(total<k){
            return 0;
        }
        while(st<=end){
            int mid=st+(end-st)/2;
            if(ispossible(candies,mid,k)){
                ans=mid;
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};