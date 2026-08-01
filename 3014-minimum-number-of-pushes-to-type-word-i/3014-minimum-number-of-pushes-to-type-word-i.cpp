class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        for(int i=0;i<word.size();i++){
            ans+=i/8+1;
        }
        return ans;
        // int ans=0;
        // for(char ch:word){
        //     ans+=ch/8+1;
        // }
        // return ans;
        
    }
};