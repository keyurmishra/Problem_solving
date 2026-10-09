class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int open=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i] == '['){
                open++;
            }
            else{
                open--;
            }
            if(open<0){
                ans=max(ans,-open);
            }
        }
        return (ans+1)/2;
        
    }
};