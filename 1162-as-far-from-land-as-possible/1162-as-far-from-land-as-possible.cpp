class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //here u have to find out the max distance 
        int n=grid.size();
        vector<vector<int>>visi(n,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>>q;
        //phele unko pakdunga jo jo 1 hy 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    visi[i][j]=1;
                }
                else{
                    visi[i][j]=0;
                }
            }
        }
        if(q.empty() || q.size()==n*n ){
            return -1;
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int maxdis=-1;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            maxdis=max(maxdis,step);
            for(int i=0;i<4;i++){
                int newr=row+delrow[i];
                int newc=col+delcol[i];
                if(newr>=0 && newc>=0 && newr<n && newc<n && visi[newr][newc]==0){
                    visi[newr][newc]=1;
                    q.push({{newr,newc} , step+1});
                }
            } 
        }
        return maxdis;
        
    }
};