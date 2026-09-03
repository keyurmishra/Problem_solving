class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //make it like a way that check the min value of that num1 if it is even make it whole even and there would be no odd element in it else make it all odd is forst element is odd 
        int n=nums1.size();
        int min_ele=nums1[0];
        for(int x:nums1){
            if(x<min_ele) min_ele=x;
        }
        if(min_ele%2!=0){
            return true;
        }
        for(int x:nums1){
            if(x%2!=0){
                return false;
            }
        }
        return true;
        
    }
};