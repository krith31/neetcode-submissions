class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int drow[]={-1,0,+1,0};
        int dcol[]={0,-1,0,+1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;
                    bool isSurrounded= true;
                    vector<pair<int,int>> current;
                    while(!q.empty()){
                        auto it=q.front();
                        q.pop();
                        int r=it.first;
                        int c=it.second;
                        current.push_back({r,c});

                        for(int i=0;i<4;i++){
                            int nrow=r+drow[i];
                            int ncol=c+dcol[i];
                            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O'){
                                if(nrow==0 || nrow==m-1 || ncol==0 || ncol==n-1){
                                    isSurrounded=false;
                                }
                                if(!vis[nrow][ncol]){
                                    vis[nrow][ncol]=1;
                                    q.push({nrow,ncol});
                                }
                            }
                        }
                    }
                    if(isSurrounded){
                        for (auto& cell : current) {
                            board[cell.first][cell.second] = 'X';
                        }
                    }
                } 
            }
        }
    }
};
