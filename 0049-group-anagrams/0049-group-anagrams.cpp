class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string,vector<string>>mp;
        // for(auto s:strs){
        //     string original_string=s;
        //     sort(s.begin(),s.end());
        //     mp[s].push_back(original_string);
        // }
        // vector<vector<string>>anagram;
        // for(auto[key,vectofstring]:mp){
        //     anagram.push_back(vectofstring);
        // }
        // return anagram;   
        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            string word=s;
            sort(word.begin(),word.end());
            mp[word].push_back(s);
            
        }   
        vector<vector<string>>ans;
        for(auto&entry:mp){
            ans.push_back(entry.second);
        }      
        return ans;
        
    }
};