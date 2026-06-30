class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int ans=0;
        for(int house:houses){
            auto it=lower_bound(heaters.begin(),heaters.end(),house);
            int right=INT_MAX;
            int left=INT_MAX;
            if(it!=heaters.end()){
                right=*it-house;
            }
            if(it!=heaters.begin()){
                it--;
                left=house-*it;
            }
            ans=max(ans,min(left,right));

        }
        return ans;
    }
};