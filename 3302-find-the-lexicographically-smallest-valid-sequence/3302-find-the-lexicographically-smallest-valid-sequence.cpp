class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
       int n=word1.length();
       int m=word2.length();
       // here if start form iterating from the first then it may be same and then find out whether it is also same for the coming char 
       //or if not same then change it and again cound like require should be equal to the given string 
       // therefore start from the last and make a suffix type vector 
       vector<int>right_hand_side_matchlength(n,0);
       int right_matched=0;
       int i=n-1;
       int j=m-1;
       while(i>=0){
        if(j>=0 && word1[i]==word2[j]){
            right_matched++;
            j--;

        }
        right_hand_side_matchlength[i]=right_matched;
        i--;

       }
       vector<int>ans;
       bool change_char=true;//can only chnage power once 
       i=0;
       j=0;
       while(i<n && j<m){
          if(word1[i]==word2[j]){
            ans.push_back(i);
            j++;
          }
          else if(change_char==true && i+1<n && right_hand_side_matchlength[i+1]>=m-j-1){//yadi yhe condition hy tabhi me power use kr sakta hy (true)
            ans.push_back(i);
            j++;
            change_char=false;// ab nhi kr sakta use this power 

          }
          i++;
       }
       return j==m?ans:vector<int>();






        
    }
};