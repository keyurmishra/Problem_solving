class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        //initially thay are one 
        int i2,i3,i5;
        i2=i3=i5=1;
        arr[1]=1;
        for(int i=2;i<=n;i++){
            int i2th_ugly=arr[i2]*2;
            int i3th_ugly=arr[i3]*3;
            int i5th_ugly=arr[i5]*5;
            int mini_ugly=min({i2th_ugly,i3th_ugly,i5th_ugly});
            arr[i]=mini_ugly;
            if(mini_ugly==i2th_ugly){
                i2++;
            }
            if(mini_ugly==i3th_ugly){
                i3++;
            }
            if(mini_ugly==i5th_ugly){
                i5++;
            }
        }
        return arr[n];
        
    }
};