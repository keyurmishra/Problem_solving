class Solution {
    public int indexsum(int val){
        int sum=0;
        while(val>0){
            int digit=val%10;
            sum+=digit;
            val/=10;
        }
        return sum;
    }
    public int smallestIndex(int[] nums) {
        for(int i=0;i<nums.length;i++){
            if(indexsum(nums[i])==i){
                return i;
            }
        }
        return -1;
        
    }
}