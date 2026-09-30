class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        using T=pair<int,int>;
        priority_queue<T,vector<T>,greater<T>> pq;
        vector<bool> vis(points.size(),false);
        pq.push({0,0});
        int total_cost=0;
        int connected_nodes=0;

        while(!pq.empty() && connected_nodes<points.size()){
            auto[cost,node]=pq.top();
            pq.pop();
            if(vis[node]) continue;

            vis[node]=true;
            total_cost+=cost;
            connected_nodes++;
            for(int i=0;i<points.size();i++){
                if(!vis[i]){
                    int dist=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                    pq.push({dist,i});
                }
            }
        }
        return total_cost;
    }
};
