class Solution {
public:
    int mySqrt(int x) {
        // here it is the concept of the monotonic function 
        //x*x==n ya x*x<n<(x+1)^2
        int st=0,end=x,ans=0;
        while(st<=end){
            long long mid=st+(end-st)/2;
            if(mid*mid>x){
                end=mid-1;
            }
            else{
                ans=mid;
                st=mid+1;
            }
        }
        return ans;
        
    }
};