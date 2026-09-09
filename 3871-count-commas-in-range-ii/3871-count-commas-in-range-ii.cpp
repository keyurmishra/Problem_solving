class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long power=1000;
        long long commas=1;
        while(power<=n){
            long long nxtpower=power*1000;
            long long count=min(n+1,nxtpower)-power;
            ans+=count  * commas;
            power=nxtpower;
            commas++;
        }
        return ans;
        
    }
};