class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return dfs(grid, i, j, m, n);
                }
            }
        }

        return 0;
    }
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        if(r<0 || r>=rows || c<0 || c>=cols) {
            return 1;
        }
        if(grid[r][c]==0) {
            return 1;
        }
        if(grid[r][c]==-1) {
            return 0;
        }
        grid[r][c] = -1;
        return dfs(grid, r+1, c, rows, cols) + 
               dfs(grid, r-1, c, rows, cols) + 
               dfs(grid, r, c+1, rows, cols) + 
               dfs(grid, r, c-1, rows, cols);
    }
};