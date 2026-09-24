class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int islands=0;
        int dcol[]={-1,0,+1,0};
        int drow[]={0,-1,0,+1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=1 && grid[i][j]=='1'){
                    islands++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto it=q.front();
                        int r=it.first;
                        int c=it.second;
                        q.pop();

                        for(int i=0;i<4;i++){
                            int nrow=r+drow[i];
                            int ncol=c+dcol[i];
                            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && vis[nrow][ncol] != 1){
                                vis[nrow][ncol]=1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
