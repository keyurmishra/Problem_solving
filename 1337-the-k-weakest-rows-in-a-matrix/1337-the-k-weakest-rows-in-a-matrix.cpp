class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<pair<int,int>>map;
        for(int i=0;i<m;i++){
            int count=0;
          for(int j=0;j<n;j++){
              count+=mat[i][j];
          }
          map.push_back({count,i});
        }
        sort(map.begin(),map.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(map[i].second);
        }
        return ans;
        
        // here i stored the count as well as the index (count,index);

        
        
    }
};