class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visi(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){//left
            if(board[i][0]=='O'){
                q.push({i,0});
                visi[i][0]=1;
            }
        }
        for(int i=0;i<n;i++){//right
            if(board[i][m-1]=='O' && !visi[i][m-1]){
                q.push({i,m-1});
                visi[i][m-1]=1;
            }
        }
        for(int i=0;i<m;i++){//top
            if(board[0][i]=='O' && !visi[0][i]){
                q.push({0,i});
                visi[0][i]=1;
            }
        }
         for(int i=0;i<m;i++){//bottom
            if(board[n-1][i]=='O' && !visi[n-1][i]){
                q.push({n-1,i});
                visi[n-1][i]=1;
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=row+delrow[i];
                int newc=col+delcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && !visi[newr][newc] && board[newr][newc]=='O'){
                    visi[newr][newc]=1;
                    q.push({newr,newc});
                }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visi[i][j]){
                    board[i][j]='X';
                    
                }
            }
        }
        cout<<"[";
        for(int i=0;i<n;i++){
            cout<<"[";
            for(int j=0;j<m;j++){
                cout<<board[i][j];
                if(j!=m-1)
                    cout<<", ";
                
            }
            cout<<"]";
            if(i!=n-1)
               cout<<","<<endl;
        }
        cout<<"]"<<endl;
    }
};