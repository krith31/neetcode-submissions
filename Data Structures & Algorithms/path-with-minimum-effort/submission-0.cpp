class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        using T=pair<int,pair<int,int>>;
        priority_queue<T,vector<T>,greater<T>> q;
        q.push({0,{0,0}});
        vector<vector<int>> min_effort(m,vector<int>(n,INT_MAX));
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        min_effort[0][0]=0;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int effort=it.first;
            int r=it.second.first;
            int c=it.second.second;

            if(r==m-1 && c==n-1){
                return effort;
            }
            for(int i=0;i<4;i++){
                int nr=drow[i]+r;
                int nc=dcol[i]+c;

                
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int max_diff=abs(heights[nr][nc]-heights[r][c]);
                    int new_effort=max(effort,max_diff);

                    if(new_effort<min_effort[nr][nc]){
                        min_effort[nr][nc]=new_effort;
                        q.push({new_effort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};