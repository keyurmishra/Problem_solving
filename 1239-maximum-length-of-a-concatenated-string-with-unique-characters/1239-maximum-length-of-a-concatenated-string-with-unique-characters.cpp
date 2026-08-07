class Solution {
public:
    bool duplicate_found(string s1,string s2){
        unordered_set<char>seen;
        for(char ch:s1){
            if(seen.find(ch) != seen.end()){
                return true;
            }
            seen.insert(ch);
        }
        // now set me s1 ke char aa chuke hy not compare with the s2 
        for(char ch:s2){
            if(seen.find(ch)!=seen.end()){
                return true;
            }
            seen.insert(ch);
        }
        return false;
    }
    int solve(vector<string>&arr , int i,string temp,int n){
        if(i>=n) return temp.length();
        int include=0,exclude=0;
        if(duplicate_found(arr[i],temp)){
            //exclude always 
            exclude=solve(arr,i+1,temp,n);
        }
        else{
            exclude=solve(arr,i+1,temp,n);
            include=solve(arr,i+1,temp+arr[i],n);
        }
        return max(exclude,include);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        return solve(arr,0,temp,n);
        
    }
};