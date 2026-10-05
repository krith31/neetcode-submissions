class Solution {
    int m,n;
public:
    int func(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i>=m || j>=n) return 1e9;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=func(i+1,j,grid,dp);
        int right=func(i,j+1,grid,dp);
       
        return dp[i][j]=grid[i][j]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,grid,dp);
    }
};