class Solution {
public:
    string reversePrefix(string word, char ch) {
        int tar=-1;
        int n1=word.length();
        for(int i=0;i<n1;i++){
            if(word[i] == ch){
                tar=i;// now i got the position 
                break;
            }
        }
        if(tar!=-1){
            int left=0;
            int right=tar;
            while(left<right){
                swap(word[left],word[right]);
                left++;
                right--;
            }
        }
        return word;
        
    }
};