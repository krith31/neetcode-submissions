class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        int ans=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            ans=t;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=r+drow[k];
                int ncol=c+dcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=1 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                } 
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=1 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
