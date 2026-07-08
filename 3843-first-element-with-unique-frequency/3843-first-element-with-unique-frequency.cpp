class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        // here we hvae to just find out the freq of every number and the freq of the frequencies 
        unordered_map<int,int>freq;
        unordered_map<int,int>freq_count;
        for(int i:nums){
            freq[i]++;
        }
        for(auto it:freq){
            freq_count[it.second]++;
        }
        for(int num:nums){
            if(freq_count[freq[num]]==1){
                return num;
            }
        }
        return -1;

        
    }
};