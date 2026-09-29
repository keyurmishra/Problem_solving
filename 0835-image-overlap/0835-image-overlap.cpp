class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        //first find out the coordinates of the first image and the 2nd image 
        int n=img1.size();
        vector<pair<int,int>>st1;
        vector<pair<int,int>>st2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j] == 1){
                    st1.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    st2.push_back({i,j});
                }
            }
        }
        // now comapre every 1 of the img1 with respect to img2 of each 1 
        map<pair<int,int>,int>mpp; // (dx,dy),count
        int ans=0;
        for(auto p1:st1){
            for(auto p2:st2){
                int dx=p2.first - p1.first;
                int dy=p2.second - p1.second;
                mpp[{dx,dy}]++;
                ans=max(ans,mpp[{dx,dy}]);
            }
        }
        return ans;
        
    }
};