class Solution {
public:
    int hIndex(vector<int>& citations) {
        //here it is already sorted 
        int n=citations.size();
        int st=0,end=n-1;
        //here it is asking do we have 5 paper with atleast 5 cit 
        // same for the next iteratiokn i=1 n-i=4  ....
        while(st<=end){
            int mid=st+(end-st)/2;
            if(citations[mid]>=n-mid){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return n-st;

        
    }
};