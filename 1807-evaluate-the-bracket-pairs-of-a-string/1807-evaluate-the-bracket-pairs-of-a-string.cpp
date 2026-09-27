class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        unordered_map<string,string>mp;
        for(auto&vec:knowledge){
            mp[vec[0]]=vec[1];
        }
        int i=0;
        string result="";
        while(i<n){
            if(s[i]=='('){
                int j=s.find(")",i+1);
                string temp=s.substr(i+1,j-i-1);
                auto it=mp.find(temp);
                //now temp ko search kro from the map
                if(it!=mp.end()){
                    result+=it->second;
                } 
                else{
                    result+="?";
                }
                i=j;
            }
            else{
                result.push_back(s[i]);
            }
            i++;
        }
        return result;
        
    }
};