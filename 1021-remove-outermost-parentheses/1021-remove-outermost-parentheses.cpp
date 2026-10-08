class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans="";
        int incr_count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(incr_count>0){
                    ans+=s[i];
                }
                incr_count++;
            }
            else{
                incr_count--;
                if(incr_count>0){
                    ans+=s[i];
                }
            }
        }
        return ans;
        
    }
};