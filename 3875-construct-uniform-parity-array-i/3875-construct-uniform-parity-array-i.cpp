class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //here the num1 is given but u have to look into the num2 make it even or the odd 
        int n=nums1.size();
        int count=0;
        for(int num:nums1){
            //now i am moving to the evry number of the array 
            if(num%2!=0){
                count++;// odd number hoga fir to 
            }
        }
        if(count==n) return true;
        if(count==0) return true;
        if(count>=1){
            return true;
        }
        return false;
    }
};