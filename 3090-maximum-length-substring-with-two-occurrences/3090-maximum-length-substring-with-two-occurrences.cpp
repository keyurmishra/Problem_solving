class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        int maxi=INT_MIN;
        unordered_map<char,int>freq;
        while(j<n){
            freq[s[j]]++;// map me stored kr rhy hy element and their char 
            while(freq[s[j]]>2){
                freq[s[i]]--;
                i++;
            }

           maxi=max(maxi,j-i+1);
           j++;
        }
        return maxi;
        
    }
};