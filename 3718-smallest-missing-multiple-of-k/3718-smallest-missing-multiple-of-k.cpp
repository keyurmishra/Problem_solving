class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // unordered_set<int>st(nums.begin(),nums.end());
        // int multiple=k;
        // while(st.count(multiple)){
        //     multiple+=k;
        // }
        // return multiple;
        unordered_set<int>mp(nums.begin(),nums.end());
        int mul=k;
        while(mp.count(mul)){
            mul+=k;
        }
        return mul;
        
    }
};