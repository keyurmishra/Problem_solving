class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry){
            //positive value banao 
            int sum=0;
            int d1=0;
            int d2=0;
            if(i>=0){
                d1=num1[i]-'0';
            }
            if(j>=0){
                d2=num2[j]-'0';
            }
            sum=d1+d2+carry;
            //but jo single ans aa rha hy use stored bhi krna hy 
            int stored=(sum%10);
            ans.push_back(stored+'0');
            carry=sum/10;
            i--;
            j--;
        }// jo ans aaya hy ulta hy 
        reverse(ans.begin(),ans.end());
        return ans;


        // //we can solve using the stack 
        // stack<int>s1;
        // stack<int>s2;
        // // iteratre inside the num1 and num2 make ch to int 
        // for(char ch:num1){
        //     //stack me push kro 
        //     s1.push(ch-'0');
        // }
        // for(char ch:num2){
        //     s2.push(ch-'0');
        // }
        // int carry=0;
        // string ans="";
        // while(!s1.empty() || !s2.empty() ||carry){
        //     int sum=carry;
        //      if(!s1.empty()){

        //      }
        // }

        
    }
};