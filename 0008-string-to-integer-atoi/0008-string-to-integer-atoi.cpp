class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        //ab chalega ek loop 
        // every char will iterate 
        int i=0;
        // if -ve and +ve arrive take that serieouslly 
        // if space comes ingnore it 
        // if char comes break that string at that point 
        while(i<n && s[i]==' '){
            i++;
        }
        long long ans=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            // if +comes nothing can u do but if -ve comes 
            if(s[i]=='-'){
                ans=-1;
                
            }
            i++;
        }
        long long num=0;
        while(i<n && isdigit(s[i])){
            int digit=s[i]-'0'; //making char to int 
            num=num*10+digit;
            if(ans*num<INT_MIN){
                return INT_MIN;
            }
            if(num*ans>INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        return num*ans;
        
    }
};