class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());
        string f=strs[0];
        string l=strs[n-1];
        string ans="";
        for(int i=0;i<min(f.length(),l.length());i++){
            if(f[i]!=l[i]){
                break;
            }
            ans+=f[i];

        }
        return ans;
    }
};