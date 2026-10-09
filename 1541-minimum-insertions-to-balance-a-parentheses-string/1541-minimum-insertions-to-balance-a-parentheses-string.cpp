class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int insertion=0;
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else{
                // if there are 2 closed 
                if(s[i+1]==')' && i+1<n){
                    i++;
                }
                else{
                    insertion++;
                }
                
                if(open>0){
                    open--;
                }
                else{
                    insertion++;
                }
            }
        }
        insertion+=2*open;
        return insertion;
        
    }
};