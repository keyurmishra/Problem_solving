class Solution {
public:
    void dfs(int node , vector<int>&visi,vector<int>adjls[]){
        visi[node]=1;
        for(auto it:adjls[node]){
            if(!visi[it]){
                dfs(it,visi,adjls);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        // here they gave us the matrix but we need the adjls which is imp 
        vector<int>adjls[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                   adjls[i].push_back(j);
                   
                }
                
            }
        }

        // visited node 
        vector<int>visi(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visi[i]){
                count++;
                dfs(i,visi,adjls);
            }
        }
        return count;


        
    }
};