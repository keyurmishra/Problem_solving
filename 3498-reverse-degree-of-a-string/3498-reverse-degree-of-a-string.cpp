class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int sum=0;
        //we use the ascii level 
        // a----(s[i]-'a')---0// but here we need this in reverse order 
        for(int i=0;i<n;i++){
            int reverse=(26-(s[i]-'a'));
            int index=(i+1);
            sum+=reverse * index;
            
        }
        return sum;
        
    }
};