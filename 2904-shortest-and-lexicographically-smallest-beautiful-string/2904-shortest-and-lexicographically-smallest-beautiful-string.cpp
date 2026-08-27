class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       int n=s.length();
       string ans="";
       int minlen=INT_MAX;
       for(int i=0;i<n;i++){
        int one_count=0;
        for(int j=i;j<n;j++){
            if(s[j]=='1') one_count++;
            if(one_count==k){
                // to ek length find out hoyegi fir to 
                int len=j-i+1;
                string curr=s.substr(i,len);//this is foe the smaller lenght 
                if(len<minlen){
                    minlen=len;
                    ans=curr;// ans to vo hoyega like substrng of the minlen 

                }
                else if(len==minlen && curr<ans){
                    ans=curr;
                }

            }
            if(one_count>k){
                break;
            }
        }
       }
       return ans;
    }
    
};