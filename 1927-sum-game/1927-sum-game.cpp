class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int leftsum=0;
        int rightsum=0;
        int leftq=0;
        int rightq=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    leftq++;
                }
                else{
                    rightq++;
                }
            }
            else{
                if(i<n/2){
                    leftsum+=num[i]-'0';
                }
                else{
                    rightsum+=num[i]-'0';
                }
            }
        }
        int totalq=leftq+rightq;
        if(totalq%2==1) return true;//alice wins 
        int left=2*leftsum+9*leftq;
        int right=2*rightsum+9*rightq;
        // if(left==right)return false;
        return (left!=right);
        

        
    }
};