class Solution {
public:
    unordered_set<string>st;
    void solve(string &s,int n,int i,string &curr,int &maxlen,int count){
        //BASE CASE 
        if(count<0)return;
        if(i==n){
            if(count ==0){
                if(curr.length()>maxlen){
                    maxlen=curr.length();
                    st.clear();
                    st.insert(curr);
                }
                else if(curr.length() == maxlen){
                    st.insert(curr);
                }
            }
            return;
        }
        //if non brakrt are there 
        if(s[i]!='(' && s[i]!=')'){
            curr.push_back(s[i]);
            solve(s,n,i+1,curr,maxlen,count);
            curr.pop_back();
            return;
        }
        //include the curr bracket 
        curr.push_back(s[i]);
        solve(s,n,i+1,curr,maxlen,count+(s[i] =='('?1:-1));
        curr.pop_back();
        //remove the curr bracket 
        solve(s,n,i+1,curr,maxlen,count);

    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        st.clear();
        int maxlen=0;
        string curr="";
        solve(s,n,0,curr,maxlen,0);
        vector<string>ans(st.begin(),st.end());
        return ans;
        
    }
};