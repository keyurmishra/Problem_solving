class Solution {
public:
    int minimumPushes(string word) {
        //in this part of the qurstion we have to find out the freq of the each char 
        vector<int>freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        //jiski jaydq freq vo sabse phele 
        sort(freq.rbegin(),freq.rend());
        int count=0;
        for(int i=0;i<26;i++){
            int ans=(i/8+1);
            count+=freq[i]*ans;
        }
        return count;
        
    }
};