class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // now using this string s we can make the window from left to right 
        // unordered_set<char>st;
        // int left=0,maxLen=s.length()-1;
        // for(int right=0;right<s.length()-1;right++){
        //     while(st.find(s[right]) != st.end()){
        //         st.erase(s[left]);
        //         left++;
        //     }
        //     st.insert(s[right]);
        //     maxLen = max(maxLen, right - left + 1);
        // }
        // return maxLen;
         unordered_set<char> st;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

        // If duplicate, shrink window
            while (st.find(s[right]) != st.end()) {
               st.erase(s[left]);
               left++;
            }

            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

         return maxLen;
        

        
    }
};