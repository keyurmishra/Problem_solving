class Solution {
public:
    void solve(int n,vector<string>&ans,int o,int c,string curr){
        //base case 
        if(o==n && c==n){
            ans.push_back(curr);
            return ;
        }
        if(o<n){
            solve(n,ans,o+1,c,curr+"(");
        }
        if(c<o){
            solve(n,ans,o,c+1,curr+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,ans,0,0,"");
        return ans;
        
    }
};