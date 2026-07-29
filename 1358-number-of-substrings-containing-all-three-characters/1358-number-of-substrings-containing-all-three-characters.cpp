class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int l=0;
        int ans=0;
        unordered_map<char,int>mpp;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
                ans+=n-r;
                mpp[s[l]]--;
                l++;
            }
        }
        return ans;
        
    }
};