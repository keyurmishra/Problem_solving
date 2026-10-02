class Solution {
public:
    vector<int>solve(string s){
        vector<int>result;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                //make a space for the right and for the left here 
                string left=s.substr(0,i);
                string right=s.substr(i+1);
                vector<int> leftresult=solve(left);
                vector<int> rightresult=solve(right);
                for(int&x:leftresult){
                    for(int&y:rightresult){
                        if(s[i]=='+'){
                            result.push_back(x+y);
                        }
                        else if(s[i]=='-'){
                            result.push_back(x-y);
                        }
                        else{
                            result.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(result.empty()){
            result.push_back(stoi(s));
        }
        return result;
    }
    vector<int> diffWaysToCompute(string s) {
        return solve(s);
        
        
    }
};