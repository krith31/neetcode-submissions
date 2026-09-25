class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int max_area=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,-1,0,+1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int current_area=0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]=0;
                    while(!q.empty()){
                        auto it=q.front();
                        q.pop();
                        int r=it.first;
                        int c=it.second;
                        current_area++;
                        for(int i=0;i<4;i++){
                            int nr=r+drow[i];
                            int nc=c+dcol[i];
                            
                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                                q.push({nr,nc});
                                grid[nr][nc]=0;
                            }
                        }
                    }
                    max_area=max(max_area,current_area);
                }
            }
        }
        return max_area;
    }
};
