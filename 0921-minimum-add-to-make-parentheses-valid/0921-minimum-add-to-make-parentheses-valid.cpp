class Solution {
public:
    int minAddToMakeValid(string s) {
        // int n=s.length();
        // int balance=0;
        // int add=0;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='('){
        //         balance++;
        //     }
        //     else{
        //         if(balance>0){
        //             balance--;
        //         }
        //         else{
        //             add++;
        //         }
        //     }

        // }
        // return balance+add;
        int n=s.length();
        int balance=0;
        int addi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                balance++;
            }
            else{
                if(balance>0){
                    balance--;
                }
                else{
                    addi++;
                }
            }
        }
        return addi+balance;
        
    }
};