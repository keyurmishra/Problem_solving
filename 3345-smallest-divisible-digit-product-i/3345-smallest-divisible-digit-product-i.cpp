class Solution {
public:
    int smallestNumber(int n, int t) {
       
        for(int i=n;i<=n+10;i++){
            int ans=i;
            int pro=1;
            while(ans>0){
                int last_digit=ans%10;
                pro=pro*last_digit;
                ans/=10;
            }
            if(pro%t==0) return i;
        }
        return n;
       
        
    }
     
};