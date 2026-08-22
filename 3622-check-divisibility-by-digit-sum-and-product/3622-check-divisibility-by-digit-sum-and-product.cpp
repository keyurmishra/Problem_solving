class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int pro=1;
        while(temp>0){
            int rem=temp%10;
            sum+=rem;
            pro=pro*rem;
            temp=temp/10;
        }
        return n%(sum+pro)==0;
        
    }
};