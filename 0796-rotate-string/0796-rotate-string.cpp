class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1=s.length();
        int n2=goal.length();
        if(n1!=n2){
            return false;
        }
        string str=s+s;
        return str.find(goal)!=string::npos;
        

        
    }
};