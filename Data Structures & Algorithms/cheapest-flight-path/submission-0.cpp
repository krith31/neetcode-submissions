class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int wt=it.second.second;
            if(stops>k) continue;
            for(auto i:adj[node]){
                int next_node=i.first;
                int edgeWt=i.second;
                if(wt+edgeWt<dist[next_node] && stops<=k){
                    dist[next_node]=wt+edgeWt;
                    q.push({stops+1,{next_node,dist[next_node]}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};
