class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>nonZero1,nonZero2;
        for (int r=0;r<n;++r) {
            for (int c=0;c<n;++c) {
                if (img1[r][c]==1)nonZero1.push_back({r, c});
                if (img2[r][c]==1)nonZero2.push_back({r, c});
            }
        }
        map<pair<int,int>,int>shiftCount;
        int maxOverlap = 0;

        for (auto& p1:nonZero1) {
            for (auto& p2:nonZero2) {
                pair<int,int> shift={p2.first-p1.first,p2.second-p1.second};
                shiftCount[shift]++;
                maxOverlap = max(maxOverlap,shiftCount[shift]);
            }
        }
        return maxOverlap;
        
    }
};