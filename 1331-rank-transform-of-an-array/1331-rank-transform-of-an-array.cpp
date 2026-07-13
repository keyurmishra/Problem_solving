class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>rank;
        //initial rank is 1 
        int initrank=1;
        for(int i:sorted){
            if(!rank.count(i))
            rank[i]=initrank++;
        }
        for(int i=0;i<n;i++){
            arr[i]=rank[arr[i]];
        }
        return arr;


        
    }
};