class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        using T=tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<>> pq;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        pq.push({grid[0][0],0,0});
        vis[0][0]=true;
        while(!pq.empty()){
            auto [wt,r,c]=pq.top();
            pq.pop();
            if(r==n-1 && c==n-1){
                return wt;
            }
            for(int i=0;i<4;i++){
                int nr=drow[i]+r;
                int nc=dcol[i]+c;
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    pq.push({max(wt,grid[nr][nc]),nr,nc});
                }
            }
        }
        return -1;
    }
};
