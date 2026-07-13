class Solution {
public:
    bool issquare(long long b){
        long long l=0,h=b;
        while(l<=h){
            long long mid=(l+h)/2;
            long long square=mid*mid;
            if(square==b) return true;
            else if(square<b) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        //my a value is changing 
        for(long long a=0;a*a<=c;a++){
            long long b=c-(a*a);
            if(issquare(b)){
                return true;
            }
        }
        return false;
        
    }
};